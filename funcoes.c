//==============================
//Autor:      Dorival Biudes
//Plataforma: MSX com Fusion C
//==============================

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

//Print com mudanca de linha
void Println(char* msg){
    Print(msg); Print("\n\r");
}

//Imprime um texto centralizado
void PrintCenter(char *msg, int col) {
    int numspaces=(col-StrLen(msg))/2;
    for(int i=0;i<numspaces;i++)
        Print(" ");
    Print(msg); Print("\n");
}

//Imprime a versao do MSX
void printModelMSX () {
    char *versao = malloc(9);
    switch (ReadMSXtype()) {
        case 0: StrConcat(versao, "MSX 1.0"); break;
        case 1: StrConcat(versao, "MSX 2.0"); break;
        case 2: StrConcat(versao, "MSX 2+ "); break;
        case 3: StrConcat(versao, "Turbo R"); break;
        default: StrConcat(versao, "MSX"); break;
    }
    Print(versao);
}

//exponencial
int powInt(int x, int y) {
    for (int i = 0; i < y; i++) { x *= 10; }
    return x;
}

//converte numero em formato texto para int
int parseInt(char* chars) {
    int sum = 0;
    int len = StrLen(chars);
    for (int x = 0; x < len; x++)     {
        int n = chars[len - (x + 1)] - '0';
        sum = sum + powInt(n, x);
    }
    return sum;
}
