set terminal png
set grid
set key left
set style data histogram
set style histogram cluster gap 1
set style fill solid border
set boxwidth .95 relative
set ylabel "Students"
set xlabel "Class"

plot	'ethnic.dat' using 2:xtic(1) title "Caucasian",\
	'ethnic.dat' using 3 title "Asian",\
	'ethnic.dat' using 4 title "Hispanic",\
	'ethnic.dat' using 5 title "African",\
	'ethnic.dat' using 6 title "Native",\
	'ethnic.dat' using 7 title "Multiple",\
	'ethnic.dat' using 8 title "Undeclared"
