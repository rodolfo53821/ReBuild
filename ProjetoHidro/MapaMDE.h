//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : MapaMDE.h
//  @ Date : 29/08/2011
//  @ Author :
//
//


#if !defined(_MAPAMDE_H)
#define _MAPAMDE_H



class MapaMDE {


public:


    //====construtores e destrutores
    MapaMDE(const char * caminhoArquivo);
    MapaMDE(MapaMDE const &);
    MapaMDE();
    ~MapaMDE();

    // =====atributos
    short int  **matrizDeElevacoes;
    int maxElev;
    int minElev;


    //====metodos
    int getNColunas();
    int getNLinhas();
    short int getResolucao();
    short int getDadoInvalido();
    char * getCaminhoArquivo();
    char * getNomeArquivo();


private:

    // =====atributos
    int nColunas;
    int nLinhas;
    double tamanhoCelula;
    double yllcorner;
    double dadoInvalido;
    double xllcorner;
    char *caminhoArquivo;
    char *nomeArquivo;


    //===metodos
    void scannerAscii(const char * caminhoArquivo);
    void substituindoVirgurlaPonto(const char * caminhoArquivo);
};

#endif  //_MAPAMDE_H