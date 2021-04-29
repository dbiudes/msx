//Gera uma pausa forcada no aplicativo
//todo: avaliar a versao do MSX para dar precisao nos segundos
void pause(int seg) {
	for (int i = 1; i < seg; ++i) {
		for (int j = 1; j < 10000; ++j) { }
	}
}

//retorna codigo ASCII de um caracter
int ascii(char key){
	return (int) key - 'A' + 65;
}

//retorna um trecho da string original conforme parametros
char* mid(char* str, int start, int len){
	char *substr = malloc(len+1);
	MemCopy(substr, &(str[start]), len);
    substr[len] = '\0';
    return substr;
}
