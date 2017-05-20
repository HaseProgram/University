/*
	Граничные условия, все дела...
*/

var R = $('#r').val();
var L = $('#l').val();
var T = $('#t').val();
var F0 = $('#f0').val();
var K0 = $('#k0').val();
var KN = $('#kn').val();
var A0 = $('#a0').val();
var AN = $('#an').val();
var N = $('#stepn').val();

var a;
var b;
var ka;
var kb;

var sln = {
	X: [],
	T: []
}

function k(x)
{
    return ka / (Number(x) - Number(kb));
}

function alpha(x)
{
    return a / (Number(x) - Number(b));
}

function hi(x1, x2)
{
    return (Number(k(x1)) + Number(k(x2))) / 2;
}

function f(x, t, r)
{
    return 2 * alpha(x) * t / r;
}

function pf(x, r)
{
    return 2 * alpha(x) / r;
}


var options = {
	showPoint: false,
	axisX: {
		labelInterpolationFnc: function(value) {
		  return Math.floor(value);
		}
	}
}

function prog(C)
{
	var ksi = [];
	var eta = []; // прогоночные коэффициенты
	
	// Начальные значения из граничных условий
	ksi[1] = -C.M0 / C.K0;
	eta[1] = C.P0 / C.K0;
	
	//прямой ход
	for(var i = 2; i <= N; i++)
	{
		ksi[i] = C.C[i-1] / (Number(C.B[i-1]) - Number(C.A[i-1] * ksi[i-1]));
		eta[i] = (Number(C.F[i-1]) + Number(C.A[i-1] * eta[i-1])) / (Number(C.B[i-1]) - Number(C.A[i-1] * ksi[i-1]));
	}
	
	sln.T[N] = (Number(C.PN) - Number(C.MN * eta[N])) / (Number(C.KN) + Number(C.MN * ksi[N]));
	
	//reverse
	for(var i = N-1; i >=0; i--)
	{
		sln.T[i] = Number(ksi[i+1] * sln.T[i+1]) + Number(eta[i+1]);
	}
	
}

function calculate()
{
	b = AN * L / (Number(AN) - Number(A0));
	a = -A0 * b;
	
	kb = KN * L / (Number(KN) - Number(K0));
	ka = -K0 * kb;
	
	var h = L / (Number(N) - 1);
	
	var C = {
		A: [],
		B: [],
		C: [],
		F: [],
		K0: 0, M0: 0, P0: 0,
		KN: 0, MN: 0, PN: 0,
		N: 0
	}; //TridiagonalCoef
	
	C.N = N;
	
	var hi12 = hi(0, h);
	var p12 = (Number(pf(0, R)) + Number(pf(h, R))) / 2;
	C.K0 = Number(hi12) + Number(h * h * p12 / 8) + Number(h * h * pf(0, R) / 4);
	C.M0 = Number(h * h * p12 / 8) - Number(hi12);
	C.P0 = Number(h * F0) + Number(h * h * (3 * Number(f(0, T, R)) + Number(f(h, T, R))) / 8);
	C.KN = -Number((Number(hi(Number(L) - Number(h), h)) + Number(alpha(L) * h)) / h)
		   -Number(h * (Number(5 * pf(L, R)) + Number(Number(L) - Number(h), R))  / 16);
	C.MN = Number(hi(Number(L) - Number(h), h) / h) -
		   Number(h * (Number(pf(L, R)) + Number(pf(Number(L) - Number(h), R))) / 16);
	C.PN = -Number(alpha(L) * T) - 
		    Number(h * (Number(3 * f(L, T, R)) + Number(f(Number(L) - Number(h), T, R))) / 8);
		   
	var x = h;
	for(var i = 1; i < N; i++)
	{
		sln.X[i] = x;
		C.A[i] = hi(Number(x) - Number(h), x) / h;
		C.C[i] = hi(x, Number(x) + Number(h)) / h;
		C.B[i] = Number(C.A[i]) + Number(C.C[i]) + Number(pf(x, R) * h);
		C.F[i] = f(x, T, R) * h;
		x = Number(x) + Number(h);
	}
	prog(C);
}

function go() {
		calculate();
		var data = {
			labels: sln.X,
			series: [sln.T]
		};
		new Chartist.Line('#chart1', data, options);
}

$(document).ready(function() {
	go();
	$('input').on('change', function() {
		solT = [];
		R = $('#r').val();
		L = $('#l').val();
		T = $('#t').val();
		F0 = $('#f0').val();
		K0 = $('#k0').val();
		KN = $('#kn').val();
		A0 = $('#a0').val();
		AN = $('#an').val();
		N = $('#stepn').val();
		go();
	});
});