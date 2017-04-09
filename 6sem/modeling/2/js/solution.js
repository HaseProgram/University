/*
	Необходимо решить систему ОДУ и вывести значения I(t), Uc(t), Ucp(t), Rp(t).
*/

var Tw = $('#tw').val();
var R = $('#r').val();
var I0 = $('#i0').val();
var Uc0 = $('#uc0').val();
var le = $('#le').val();
	
function getTM(I) {
	var lastIndex = 0;
	if(I < TMI[0][0]) {
		lastIndex = 1;
	} else if(I >= TMI[TMI.length-1][0]) {
		lastIndex = TMI.length - 1;
	} else {
		while(I < TMI[lastIndex][0]) {
			lastIndex++;
		}
		lastIndex++;
	}
	
	var tm = [];
	var t = TMI[lastIndex - 1][1] + (TMI[lastIndex][1] - TMI[lastIndex - 1][1]) / (TMI[lastIndex][0] - TMI[lastIndex - 1][0]) * (I - TMI[lastIndex - 1][0]);
	var m = TMI[lastIndex - 1][2] + (TMI[lastIndex][2] - TMI[lastIndex - 1][2]) / (TMI[lastIndex][0] - TMI[lastIndex - 1][0]) * (I - TMI[lastIndex - 1][0]);
	tm.push(t);
	tm.push(m);
}

function getPressure(Tr) {
	return 0;
}

function getResistance(I) {
	I = Math.abs(I); // can be < 0
	
	// Before we start calculate resistance we need get T(r) array.
	// Interpolate TMI:
	var TMIres = getTM(I);
	var t = TMIres[0];
	var m = TMIres[1];
	
	var Tr = [];
	var step = R / 41;
	
	for (var i = 0, var r = 0; i < 41; i++, r += step) {
		var Tri = (Tw - t) * Math.pow((r / R), m) + t;
		Tr.push(Tri);
	}

	var p = getPressure(Tr);
	
	// Calculate integral with simpson method
	var integral = 0;
	var h = R / 41; // h = (b - a) / N;
	
	
	return le / 2 / Math.PI / integral;
}

function runge() {
	var Resistance = getResistance(I0);
	
}

function trapeze() {
	
}

$(document).ready(function() {
	
	
	
	$('input').on('change', function() {
		if($('input[name=method]:checked', 'form').val() == "runge") {
			runge();
		}
		else {
			trapeze();
		}
	});
});