/*
	Необходимо решить систему ОДУ и вывести значения I(t), Uc(t), Ucp(t), Rp(t).
*/

var h = $('#step').val();
var stepn = $('#stepn').val();

function f(x, y) {
	return Number(x*x) + Number(y*y);
}

function pow(arg, st) {
	return Math.pow(Number(arg),Number(st));
}

function sqrt(arg) {
	return Math.sqrt(Number(arg));
}

function go() {
var insert = "<tr>" + 
"<th>X</th>" +
"<th>М.Пикара(1)</th><th>М.Пикара(2)</th><th>М.Пикара(3)</th><th>М.Пикара(4)</th>" + 
"<th>М.Рунге-Кутта(а=0.5)</th><th>М.Рунге-Кутта(а=1)</th>" +
"<th>Явная схема</th><th>Неявная схема</th></tr>";
	var x = 0;
    var xn = 0;
    var run_kut05 = 0;
    var run_kut1 = 0;
    var expl = 0;
    var impl = 0;
    for (var i = 0; i < stepn; i++)
    {
        x = Number(x) + Number(h);
        var picar1 = Number(pow(x, 3)) / 3;
        var picar2 = Number(picar1) + Number(pow(x, 7) / 63);
        var picar3 = Number(picar2) + Number(2*pow(x, 11)/2079) + Number(pow(x, 15)/59535);
        var picar4 = Number(picar2) + Number(2*pow(x, 11)/2079) + Number(13*pow(x, 15)/218295) +
            Number(82*pow(x, 19)/37328445) + Number(662*pow(x, 23)/10438212015) + Number(4*pow(x, 27)/3341878155) +
            Number(pow(x, 31)/109876902975);

        run_kut05 = Number(run_kut05) + Number(0.5 * h * (Number(f(xn, run_kut05)) + Number(f(x + h, Number(run_kut05) + Number(h*f(xn, run_kut05))))));
        run_kut1 = Number(run_kut1) + Number(h / 2 * f(x, Number(run_kut1) + Number(h / 2 * f(xn, run_kut1))));

        expl = Number(expl) + Number(h * f(xn, expl));
        impl = (-sqrt(Number(-4*h*h*x*x) - Number(4*h*impl) + 1) + 1) / 2 / h;
		
		insert += "<tr><td>" + Math.floor(x*10000000000)/10000000000 + 
		//"</td><td>" + Math.floor(picar1*1000000000000)/1000000000000  + 
		"</td><td>" + picar1.toExponential(5)  +
		"</td><td>" + picar2.toExponential(5)  + 
		"</td><td>" + picar3.toExponential(5)  + 
		"</td><td>" + picar4.toExponential(5)  + 
		"</td><td>" + run_kut05.toExponential(5)  + 
		"</td><td>" + run_kut1.toExponential(5)  + 
		"</td><td>" + expl.toExponential(5)  + 
		"</td><td>" + impl.toExponential(5)  + "</td></tr>";
		
        xn = Number(xn) + Number(h);
    }
	$('#restab').html(insert);
}

$(document).ready(function() {
	go();
	$('input').on('change', function() {
		h = $('#step').val();
		stepn = $('#stepn').val();
		console.log(h);
		console.log(stepn);
		go();
	});
});