/*
	Граничные условия, все дела...
*/
var originalLog = console.log
console.log=function(obj){
    originalLog(JSON.parse(JSON.stringify(obj)))
}

var WT = [300, 400, 500, 600, 700, 800, 900, 1000, 1200, 1400, 1600, 1800, 2000, 2200, 2400, 2600, 2800, 3000];
var WC = [2.544, 2.615, 2.656, 2.689, 2.717, 2.748, 2.783, 2.817, 2.893, 2.977, 3.070, 3.124, 3.270, 3.381, 3.502, 3.640, 3.792, 3.968];
var WK = [0.163, 0.156, 0.146, 0.137, 0.130, 0.124, 0.120, 0.117, 0.114, 0.111, 0.110, 0.109, 0.108, 0.107, 0.107, 0.107, 0.109, 0.108];

var R = $('#r').val();
var L = $('#l').val();
var T = $('#t').val();
var F0 = $('#f0').val();
var A0 = $('#a0').val();
var AN = $('#an').val();
var N = $('#stepn').val();
var StT = $('#stept').val();

var a; // для вычисления теплоотдачи
var b;

var sln = {
	X: [],
	T: []
}

function abs(x)
{
	return Math.abs(x);
}

function k(x)
{
	var ind = 0;
	if(x <= WT[0]) { ind = 1; }
	else if (x > WT[WT.length-1]) { ind = WT.length-1; }
	else while (WT[ind] < x) { ind = Number(ind) + 1; }
	return (Number(WK[ind-1]) + Number(Number(WK[ind]) - Number(WK[ind-1])) * (Number(x) - Number(WT[ind-1])) / (Number(WT[ind]) - Number(WT[ind-1])));
}

function c(x)
{
	var ind = 0;
	if(x <= WT[0]) { ind = 1; }
	else if (x > WT[WT.length-1]) { ind = WT.length-1; }
	else while (WT[ind] < x) { ind = Number(ind) + 1; }
	return (Number(WC[ind-1]) + Number(Number(WC[ind]) - Number(WC[ind-1])) * (Number(x) - Number(WT[ind-1])) / (Number(WT[ind]) - Number(WT[ind-1])));
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

function tridiagonal_solve(C, y)
{
    var n = C.N;
    var ksi = [];
    var eta = []; // Прогоночные коэффициенты
    // Начальные значения из граничных условий
    ksi[1] = - C.M0 / C.K0;
    eta[1] = C.P0 / C.K0;
    // Прямой ход
    for (var i = 2; i <= n; i++)
    {
        ksi[i] = C.D[i-1] / (Number(C.B[i-1]) - Number(C.A[i-1] * ksi[i-1]));
        eta[i] = (Number(C.F[i-1]) + Number(C.A[i-1] * eta[i-1])) / (Number(C.B[i-1]) - Number(C.A[i-1] * ksi[i-1]));
    }

    // Yn из граничных условий
    y[n] = (Number(C.PN) - Number(C.MN * eta[n])) / (Number(C.KN) + Number(C.MN * ksi[n]));
    // Обратный ход
    for (var i = n-1; i >= 0; i--)
    {
        y[i] = Number(ksi[Number(i)+1] * y[Number(i)+1]) + Number(eta[Number(i)+1]);
    }
	
	return y;
}


function calculate()
{
	// Параметры для вычисления теплоотдачи
	b = AN * L / (Number(AN) - Number(A0));
	a = -A0 * b;
	
	var h = L / (Number(N) - 1); // шаг по Х
	
	sln.X[0] = 0;
	var x = 0;
	
	// Заполняем массивы для прогонки
    for (var i = 1; i < N; i++)
    {
        x = Number(x) + Number(h);
        sln.X[i] = x;
    }
	
	var dmax = 0; // Максимальное изменение
    var imax = 0;
    sln.T[0] = [];
	sln.T[0].length = Number(N)+1;
	
    // В момент времени t = 0 температура на всей длине равна температуре окружающей среды
    for (var i = 0; i < sln.T[0].length; i++)
        sln.T[0][i] = T;
    var Told = sln.T[0][0];
	
	do { // внешний цикл по времени
	
		var Tpast = sln.T[sln.T.length-1];
		
		// Вектор решения для текущего времени, начальное приближение - решение с предыдущего слоя
		var Tnew = sln.T[sln.T.length-1];

		do {
			
			var TLast = Tnew;
			var C = {
				A: [],
				B: [],
				D: [],
				F: [],
				K0: 0, M0: 0, P0: 0,
				KN: 0, MN: 0, PN: 0,
				N: 0
			}; //TridiagonalCoef
			
			C.N = N;
			//console.log(sln.T);
			var vhi12 = hi(Tnew[0], Tnew[1]);
			var vp12 = (Number(pf(0, R)) + Number(pf(h, R))) / 2;
			var vC0 = c(Tnew[0]);
            var vC12 = (Number(c(Tnew[0])) + Number(c(Tnew[1])))/2;
            var vp0 = pf(0, R);
            var vf0 = f(0, T, R);
            var vf1 = f(h, T, R);
			
			
			C.K0 = StT * Number(Number(vhi12/h) + Number(h*vp12/8) + Number(h*vp0/4)) + Number(h*vC0/4) + Number(h*vC12/8);
            C.M0 = StT * Number(Number(h*vp12/8) - Number(vhi12/h)) + Number(h*vC12/8);
            C.P0 = Number(F0*StT) + Number(h*StT/8*(3*vf0 + vf1)) + Number(h*vC0*Tpast[0]/4) + Number(h*vC12*(Number(Tpast[0]) + Number(Tpast[1]))/8);
			
			var vCN = c(Tnew[N]);
            var vCN12 = Number(c(Tnew[N]) + Number(c(Tnew[Number(N)-1])))/2;
            var vhiN12 = hi(Tnew[Number(N)-1], Tnew[N]);
            var vpN12 = (Number(pf(L, R)) + Number(pf(Number(L)-Number(h), R))) / 2;
            var vpN = pf(L, R);
            var vfN = f(L, T, R);
            var vfN1 = f(Number(L)-Number(h), T, R);
			
			
			C.KN = Number(-StT*(Number(vhiN12/h) + Number(alpha(L)) + Number(vpN*h/4) + Number(vpN12*h/8))) + Number(h*vCN/4) + Number(h*vCN12/8);
            C.MN = Number(StT*(Number(vhiN12/h) - Number(h*vpN12/8))) + Number(h*vCN12/8);
            C.PN = Number(-alpha(L)*T*StT) - Number(StT*h/8*(Number(3*vfN) + Number(vfN1))) + Number(h/4*vCN*Tpast[N]) + Number(h/8*vCN12*(Number(Tpast[N])+Number(Tpast[N-1])));
			
			// Коэффициенты из разностной схемы, полученной -из исходного уравнения теплопроводности;
            // Они не используются непосредственно в прогонке, но на них строятся данные для прогонки
            // линеаризованной схемы
            C.A.push(0);
            C.D.push(0);
            C.B.push(0);
            C.F.push(0);
            var vx = h;
            for (var i = 1; i < N; i++)
            {
                C.A.push(StT * hi(Tnew[i-1], Tnew[i]) / h);
                C.D.push(StT * hi(Tnew[i], Tnew[Number(i)+1]) / h);
                C.B.push(Number(C.A[C.A.length-1]) + Number(C.D[C.D.length-1]) + Number(pf(vx, R) * h * StT) + Number(c(Tnew[i]) * h));
                C.F.push(Number(c(Tnew[i]) * h * Tpast[i]) + Number(f(vx, T, R)*h*StT));
                vx = Number(vx) + Number(h);
            }
		
			Tnew = tridiagonal_solve(C, Tnew);

            dmax = 0; // Максимальное изменение
            imax = 0;
			
			console.log(sln);
            for (var i = 0; i < Tnew.length; i++)
                if (abs(Number(Tnew[i]) - Number(TLast[i])) > dmax)
                {
                    dmax = abs(Number(Tnew[i]) - Number(TLast[i]));
                    imax = i;
                }
			
		} while(abs(dmax / Tnew[imax]) > 1e-4);
		
		dmax = 0; // Максимальное изменение
        imax = 0;

        for (var i = 0; i < Tnew.length; i++)
            if (abs(Number(Tnew[i]) - Number(Tpast[i])) > dmax)
            {
                dmax = abs(Number(Tnew[i]) - Number(Tpast[i]));
                imax = i;
            }
        sln.T.push(Tnew);
		console.log(sln.T);
		console.log(dmax);
		console.log(imax);
	} while(abs(dmax / sln.T[sln.T.length-1][imax]) > 1e-4);
	//console.log(sln.T);
}

function go() {
		calculate();
		var data = {
			labels: sln.X,
			series: [sln.T[0], sln.T[StT-1]]
		};
		new Chartist.Line('#chart1', data, options);
}

$(document).ready(function() {
	go();
	$('input').on('change', function() {
		solT = [];
		var R = $('#r').val();
		var L = $('#l').val();
		var T = $('#t').val();
		var F0 = $('#f0').val();
		var A0 = $('#a0').val();
		var AN = $('#an').val();
		var N = $('#stepn').val();
		var StT = $('#stept').val();
		go();
	});
});