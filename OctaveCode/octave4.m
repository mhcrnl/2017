#! /bin/octave -qf

printf("%s", program_name());
arg_list = argv();
for i = 1:nargin
	printf("%s", arg_list{i});
endfor
printf("\n");

# Definirea unei functii in Octave
function nume
	printf("Octave function!\n");
	printf("\a");
endfunction

# Definirea unei functii cu argumente un mesaj iar \a un biip
function nume1 (mesaj)
	printf("\a%s\n", mesaj);
endfunction

# Def. unei funct. cu valoare returnata
