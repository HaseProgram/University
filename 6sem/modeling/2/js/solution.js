/*
	Необходимо решить систему ОДУ и вывести значения I(t), Uc(t), Ucp(t), Rp(t).
*/

var Tw = $('#tw').val();
var R = $('#r').val();
var I0 = $('#i0').val();
var Uc0 = $('#uc0').val();
var le = $('#le').val();
var lk = $('#lk').val();
var ck = $('#ck').val();
var rk = $('#rk').val();
var p0 = $('#p0').val();
var tstart = $('#ts').val();
var step = $('#step').val();
var stepn = $('#stepn').val();
	
function getTM(I) {
	var lastIndex = 0;
	if(I <= TMI[0][0]) {
		lastIndex = 1;
	} else if(I >= TMI[TMI.length-1][0]) {
		lastIndex = TMI.length - 1;
	} else {
		while(I > TMI[lastIndex][0]) {
			lastIndex++;
		}
	}
	var tm = [];
	var t = TMI[lastIndex - 1][1] + (TMI[lastIndex][1] - TMI[lastIndex - 1][1]) / (TMI[lastIndex][0] - TMI[lastIndex - 1][0]) * (I - TMI[lastIndex - 1][0]);
	var m = TMI[lastIndex - 1][2] + (TMI[lastIndex][2] - TMI[lastIndex - 1][2]) / (TMI[lastIndex][0] - TMI[lastIndex - 1][0]) * (I - TMI[lastIndex - 1][0]);
	tm.push(t);
	tm.push(m);
	return tm;
}

function getSigma(Tri, p) {
	var lastIndexT = 0;
	if(Tri <= sigma[0][0]) {
		lastIndexT = 1;
	} else if(Tri >= sigma[sigma.length-1][0]) {
		lastIndexT = sigma.length - 1;
	} else {
		while(Tri > sigma[lastIndexT][0]) {
			lastIndexT++;
		}
	}
	
	var lastIndexP = 2;
	var pl = 15;
	if (p > 15) {
		lastIndexP = 3;
		pl = 25;
	}
	
	var sigma1 = logsigma[lastIndexT-1][lastIndexP-1] + (logsigma[lastIndexT][lastIndexP-1] - logsigma[lastIndexT-1][lastIndexP-1]) * (Tri - sigma[lastIndexT-1][0]) / (sigma[lastIndexT][0] - sigma[lastIndexT-1][0]);
	var sigma2 = logsigma[lastIndexT-1][lastIndexP] + (logsigma[lastIndexT][lastIndexP] - logsigma[lastIndexT-1][lastIndexP]) * (Tri - sigma[lastIndexT-1][0]) / (sigma[lastIndexT][0] - sigma[lastIndexT-1][0]);
	sigma1 = Math.exp(sigma1);
	sigma2 = Math.exp(sigma2);
	return sigma1 + (sigma2 - sigma1) * (p - pl + 10) / (10); //  / p1-p0
}

function getN(Tri, p) {

	var lastIndexN = 0;
	if(Tri <= n[0][0]) {
		lastIndexN = 1;
	} else if(Tri >= n[n.length-1][0]) {
		lastIndexN = n.length - 1;
	} else {
		while(Tri > n[lastIndexN][0]) {
			lastIndexN++;
		}
	}
	
	var lastIndexP = 2;
	var pl = 15;
	if (p > 15) {
		lastIndexP = 3;
		pl = 25;
	}
	
	var n1 = logn[lastIndexN-1][lastIndexP-1] + (logn[lastIndexN][lastIndexP-1] - logn[lastIndexN-1][lastIndexP-1]) * (Tri - n[lastIndexN-1][0]) / (n[lastIndexN][0] - n[lastIndexN-1][0]);
	var n2 = logn[lastIndexN-1][lastIndexP] + (logn[lastIndexN][lastIndexP] - logn[lastIndexN-1][lastIndexP]) * (Tri - n[lastIndexN-1][0]) / (n[lastIndexN][0] - n[lastIndexN-1][0]);
	n1 = Math.exp(n1);
	n2 = Math.exp(n2);
	//console.log("N1:" + n1 + "; N2: " + n2);
	return n1 + (n2 - n1) * (p - pl + 10) / (10); //  / p1-p0
}

function getPressureIntegral(Tr, p) {
	var integral = 0;
	var rad = 0;
	var h = R / 40; // h = (b - a) / N;
	var n = 0;
	
	for(var k = 1; k < 40; k++) {
		rad = rad + h;
		n = getN(Tr[k], p);
		if(k % 2) {
			integral = integral + 4 * n * rad;
		} else {
			integral = integral + 2 * n * rad;
		}
	}
	
	n = getN(Tr[40], p);
	
	integral += n * R;
	integral = integral * h / 3;
	var res = integral * 2 / R / R - p0 * 7242 / tstart;
	return res;
}

function getPressure(Tr) {
	// Get interval with answer
	var left = 1;
	var step = 1;
	while(getPressureIntegral(Tr, left) * getPressureIntegral(Tr, left+step) > 0) {
		left += step;
	}
	
	var right = left + step;
	var p = (left + right) / 2;
	while(Math.abs(right - left) / p > 1e-4) {
		if(getPressureIntegral(Tr, left) * getPressureIntegral(Tr, p) < 0) {
			right = p;
		} else {
			left = p;
		}
		p = (left + right) / 2;
	}
	return p;
}

function getResistance(I) {
	I = Math.abs(I); // can be < 0
	
	// Before we start calculate resistance we need get T(r) array.
	// Interpolate TMI:
	var TMIres = [];
	TMIres = getTM(I);
	var t = TMIres[0];
	var m = TMIres[1];

	var Tr = [];
	var step = R / 40;
	var rad = 0;
	
	for (var k = 0; k < 41; k++) {
		var Tri = (Tw - t) * Math.pow((rad / R), m) + t;
		Tr.push(Tri);
		rad += step;
	}
	
	var p = getPressure(Tr);
	//console.log("P:"+p);
	// Calculate integral with simpson method
	var integral = 0;
	rad = 0; 
	var h = R / 40; // h = (b - a) / N;
	var sgm = 0;
	
	for(var k = 1; k < 40; k++) {
		rad = rad + h;
		sgm = getSigma(Tr[k], p);
		//console.log(p);
		if(k % 2) {
			integral = integral + 4 * sgm * rad;
		} else {
			integral = integral + 2 * sgm * rad;
		}
	}
	
	sgm = getSigma(Tr[40], p);
	integral += sgm * R;
	integral = integral * h / 3;
	return le / 2 / Math.PI / integral;
}

function fi(I, Uc, Rf) {
	var rr = Number(rk) + Number(Rf);
	return (Uc - rr * I) / lk;
}

function fu(I) {
	return - I / ck;
}

function runge() {
	//console.log(getSigma(6500, 10)); return;
	//console.log(getN(3750, 10));
	//return;
	var Resistance = getResistance(I0);
	//console.log(Resistance); 
	//return;
	var I = I0;
	var Uc = Uc0;
	var U = I * Resistance;
	var t = 0;
	
	var k = [];
	var m = [];
	
	for(var count = 0; count < stepn; count++) {
		t += Number(step);
		Resistance = getResistance(I);
		k[0] = fi(I, Uc, Resistance);
		
		m[0] = fu(I);
		//console.log(k); return;
		
		var I1 = Number(I) + Number(step) * k[0] / 2;
		var U1 = Number(Uc) + Number(step) * m[0] / 2;
		Resistance = getResistance(I1);
		k[1] = fi(I1, U1, Resistance);
		m[1] = fu(I1);
		
		I1 = Number(I) + Number(step) * k[1] / 2;
		U1 = Number(Uc) + Number(step) * m[1] / 2;
		Resistance = getResistance(I1);
		k[2] = fi(I1, U1, Resistance);
		m[2] = fu(I1);
		
		I1 = Number(I) + Number(step) * k[2] / 2;
		U1 = Number(Uc) + Number(step) * m[2] / 2;
		Resistance = getResistance(I1);
		k[3] = fi(I1, U1, Resistance);
		m[3] = fu(I1);
		
		I = Number(I) + Number(step) / 6 * (k[0] + 2*k[1] + 2*k[2] + k[3]);
		Uc = Number(Uc) + Number(step) / 6 * (m[0] + 2*m[1] + 2*m[2] + m[3]);
		Resistance = getResistance(I);
		U = I * Resistance;
		//console.log(I);
		solI.push(I);
		solUc.push(Uc);
		solR.push(Resistance);
		solU.push(U);
		solT.push(t);
	}
	
}
	
function trapeze() {
	
}

var options = {
	showPoint: false,
	axisX: {
		labelInterpolationFnc: function(value) {
		  return Math.floor(value*100)/100;
		}
	}
}

function go() {
	if($('input[name=method]:checked', 'form').val() == "runge") {
			runge();
		}
		else {
			trapeze();
		}
		
		var data = {
			labels: solT,
			series: [solI, solUc, solU]
		};
		new Chartist.Line('#chart1', data, options);
		var data2 = {
			labels: solT,
			series: [solR]
		};
		new Chartist.Line('#chart2', data2, options);
		console.log(data, solT, solI);
		 
		// new Chartist.Line('.ct-chart-2', data2, options);
}

$(document).ready(function() {
	for(var k = 0; k < sigma.length; k++) {
		var logsigmat = [];
		var lognt = [];
		logsigmat.push(0);
		lognt.push(0);
		for(var l = 1; l < 4; l++) {
			logsigmat.push(Math.log(sigma[k][l]));
			lognt.push(Math.log(n[k][l]));
			//console.log(sigma[k][l]);
		}
		//console.log(logsigmat);
		logsigma.push(logsigmat);
		logn.push(lognt);
	}
	go();
	$('input').on('change', function() {
		solI = [];
solUc = [];
solR = [];
solU = [];
solT = [];
 Tw = $('#tw').val();
 R = $('#r').val();
 I0 = $('#i0').val();
 Uc0 = $('#uc0').val();
 le = $('#le').val();
 lk = $('#lk').val();
 ck = $('#ck').val();
 rk = $('#rk').val();
 p0 = $('#p0').val();
 tstart = $('#ts').val();
 step = $('#step').val();
 stepn = $('#stepn').val();
		go();
	});
});