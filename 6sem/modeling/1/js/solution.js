/*
	Необходимо решить систему ОДУ и вывести значения I(t), Uc(t), Ucp(t), Rp(t).
*/

var h = $('#step').val();
var stepn = $('#stepn').val();
var insert = "<tr>" + 
"<th>X</th>" +
"<th>М.Пикара(1)</th><th>М.Пикара(2)</th><th>М.Пикара(3)</th><th>М.Пикара(4)</th>" + 
"<th>М.Рунге-Кутта(а=0.5)</th><th>М.Рунге-Кутта(а=1)</th>" +
"<th>Явная схема</th><th>Неявная схема</th></tr>";

function f(x, y) {
	return Number(x*x) + Number(y*y);
}

function pow(arg, st) {
	return Math.pow(Number(arg),Number(st));
}

function sqrt(arg) {
	console.log(arg);
	return Math.sqrt(Number(arg));
}

function go() {
	var x = 0;
    var xn = 0;
    var run_kut05 = 0;
    var run_kut1 = 0;
    var expl = 0;
    var impl = 0;
    for (var i = 0; i < stepn; i++)
    {
        x = Number(x) + Number(h);
        var picard1 = Number(pow(x, 3)) / 3;
        var picard2 = Number(picard1) + Number(pow(x, 7) / 63);
        var picard3 = Number(picard2) + Number(2*pow(x, 11)/2079) + Number(pow(x, 15)/59535);
        var picard4 = Number(picard2) + Number(2*pow(x, 11)/2079) + Number(13*pow(x, 15)/218295) +
            Number(82*pow(x, 19)/37328445) + Number(662*pow(x, 23)/10438212015) + Number(4*pow(x, 27)/3341878155) +
            Number(pow(x, 31)/109876902975);

        run_kut05 = Number(run_kut05) + Number(0.5 * h * (Number(f(xn, run_kut05)) + Number(f(x, Number(run_kut05) + Number(h*f(xn, run_kut05))))));
        run_kut1 = Number(run_kut1) + Number(h * f(x, Number(run_kut05) + Number(h*f(xn, run_kut05))));

        expl = Number(expl) + Number(h * f(xn, expl));
        impl = (-sqrt(Number(-4*h*h*x*x) - Number(4*h*impl) + 1) + 1) / 2 / h;
		
		insert += "<tr><td>" + Math.round(Math.floor(x*100000)/100) + 
		"</td><td>" + Math.floor(picard1*10000000000)/10000000000  + 
		"</td><td>" + Math.floor(picard2*10000000000)/10000000000  + 
		"</td><td>" + Math.floor(picard3*10000000000)/10000000000  + 
		"</td><td>" + Math.floor(picard4*10000000000)/10000000000  + 
		"</td><td>" + Math.floor(run_kut05*10000000000)/10000000000  + 
		"</td><td>" + Math.floor(run_kut1*10000000000)/10000000000  + 
		"</td><td>" + Math.floor(expl*10000000000)/10000000000  + 
		"</td><td>" + Math.floor(impl*10000000000)/1000000000  + "</td></tr>";
		
        xn = Number(xn) + Number(h);
    }
	$('#restab').html(insert);
}

$(document).ready(function() {
	go();
	$('input').on('change', function() {
		step = $('#step').val();
		stepn = $('#stepn').val();
		go();
	});
});