#include <stdio.h>
#include <stdlib.h>

#define TABULEIRO_QUANTIDADE_LINHAS 10
#define TABULEIRO_QUANTIDADE_COLUNAS 10
#define HABILIDADE_QUANTIDADE_LINHAS 3
#define HABILIDADE_QUANTIDADE_COLUNAS 5
#define CARACTERE_AGUA 0
#define CARACTERE_NAVIO 3
#define CARACTERE_HABILIDADE 5

static void aplicar_habilidade(
    int tabuleiro[TABULEIRO_QUANTIDADE_LINHAS][TABULEIRO_QUANTIDADE_COLUNAS],
    int habilidade[HABILIDADE_QUANTIDADE_LINHAS][HABILIDADE_QUANTIDADE_COLUNAS],
    int linhaInicial,
    int colunaInicial)
{
    for (int linhaIndice = 0; linhaIndice < HABILIDADE_QUANTIDADE_LINHAS; linhaIndice++)
    {
        for (int colunaIndice = 0; colunaIndice < HABILIDADE_QUANTIDADE_COLUNAS; colunaIndice++)
        {
            if (habilidade[linhaIndice][colunaIndice] == 0)
            {
				continue;
            }

			int linhaTabuleiro = linhaInicial + linhaIndice;
            int colunaTabuleiro = colunaInicial + colunaIndice;
            if ((linhaTabuleiro < 0) ||
                (linhaTabuleiro >= TABULEIRO_QUANTIDADE_LINHAS) ||
                (colunaTabuleiro < 0) ||
                (colunaTabuleiro >= TABULEIRO_QUANTIDADE_COLUNAS) ||
                (tabuleiro[linhaTabuleiro][colunaTabuleiro] == 3))
			{
                continue;
            }

			tabuleiro[linhaTabuleiro][colunaTabuleiro] = CARACTERE_HABILIDADE;
        }
    }
}

int main()
{
    const int TAMANHO_NAVIO = 3;
	const int NAVIO_VERTICAL_LINHA_INICIAL = 0, NAVIO_VERTICAL_COLUNA_INICIAL = 0;
	const int NAVIO_HORIZONTAL_LINHA_INICIAL = 5, NAVIO_HORIZONTAL_COLUNA_INICIAL = 4;
	const int NAVIO_DIAGONAL_1_LINHA_INICIAL = 7, NAVIO_DIAGONAL_1_COLUNA_INICIAL = 7;
    const int NAVIO_DIAGONAL_2_LINHA_INICIAL = 6, NAVIO_DIAGONAL_2_COLUNA_INICIAL = 0;
	const int HABILIDADE_CONE_LINHA_INICIAL = 0, HABILIDADE_CONE_COLUNA_INICIAL = 0;
	const int HABILIDADE_CRUZ_LINHA_INICIAL = 4, HABILIDADE_CRUZ_COLUNA_INICIAL = 4;
	const int HABILIDADE_OCTAEDRO_LINHA_INICIAL = 6, HABILIDADE_OCTAEDRO_COLUNA_INICIAL = 6;

    int tabuleiro[TABULEIRO_QUANTIDADE_LINHAS][TABULEIRO_QUANTIDADE_COLUNAS] = { CARACTERE_AGUA };
    int habilidadeCone[HABILIDADE_QUANTIDADE_LINHAS][HABILIDADE_QUANTIDADE_COLUNAS] =
    {
	    {0, 0, 1, 0, 0},
	    {0, 1, 1, 1, 0},
	    {1, 1, 1, 1, 1}
    };
    int habilidadeCruz[HABILIDADE_QUANTIDADE_LINHAS][HABILIDADE_QUANTIDADE_COLUNAS] =
    {
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0}
	};
    int habilidadeOctaedro[HABILIDADE_QUANTIDADE_LINHAS][HABILIDADE_QUANTIDADE_COLUNAS] =
    {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
	};

    // Validações de posicionamento dos navios
    if ((NAVIO_VERTICAL_COLUNA_INICIAL < 0) ||
        (NAVIO_VERTICAL_COLUNA_INICIAL > TABULEIRO_QUANTIDADE_COLUNAS) ||
        (NAVIO_VERTICAL_LINHA_INICIAL < 0) ||
        (NAVIO_VERTICAL_LINHA_INICIAL > TABULEIRO_QUANTIDADE_LINHAS) ||
        (((NAVIO_VERTICAL_LINHA_INICIAL - 1) + TAMANHO_NAVIO) > TABULEIRO_QUANTIDADE_LINHAS))
    {
        printf("Navio vertical não cabe no tabuleiro.\n");
        exit(1);
    }

    if ((NAVIO_HORIZONTAL_LINHA_INICIAL < 0) ||
        (NAVIO_HORIZONTAL_LINHA_INICIAL > TABULEIRO_QUANTIDADE_LINHAS) ||
        (NAVIO_HORIZONTAL_COLUNA_INICIAL < 0) ||
        (NAVIO_HORIZONTAL_COLUNA_INICIAL > TABULEIRO_QUANTIDADE_COLUNAS) ||
        (((NAVIO_HORIZONTAL_COLUNA_INICIAL - 1) + TAMANHO_NAVIO) > TABULEIRO_QUANTIDADE_COLUNAS))
    {
        printf("Navio horizontal não cabe no tabuleiro.\n");
        exit(1);
    }

    if ((NAVIO_DIAGONAL_1_LINHA_INICIAL < 0) ||
        (NAVIO_DIAGONAL_1_LINHA_INICIAL > TABULEIRO_QUANTIDADE_LINHAS) ||
        (NAVIO_DIAGONAL_1_COLUNA_INICIAL < 0) ||
        (NAVIO_DIAGONAL_1_COLUNA_INICIAL > TABULEIRO_QUANTIDADE_COLUNAS) ||
        ((NAVIO_DIAGONAL_1_LINHA_INICIAL + TAMANHO_NAVIO) > TABULEIRO_QUANTIDADE_LINHAS) ||
        ((NAVIO_DIAGONAL_1_COLUNA_INICIAL + TAMANHO_NAVIO) > TABULEIRO_QUANTIDADE_COLUNAS))
    {
        printf("Navio diagonal 1 não cabe no tabuleiro.\n");
        exit(1);
    }

    if ((NAVIO_DIAGONAL_2_LINHA_INICIAL < 0) ||
        (NAVIO_DIAGONAL_2_LINHA_INICIAL > TABULEIRO_QUANTIDADE_LINHAS) ||
        (NAVIO_DIAGONAL_2_COLUNA_INICIAL < 0) ||
        (NAVIO_DIAGONAL_2_COLUNA_INICIAL > TABULEIRO_QUANTIDADE_COLUNAS) ||
        ((NAVIO_DIAGONAL_2_LINHA_INICIAL + TAMANHO_NAVIO) > TABULEIRO_QUANTIDADE_LINHAS) ||
        ((NAVIO_DIAGONAL_2_COLUNA_INICIAL + TAMANHO_NAVIO) > TABULEIRO_QUANTIDADE_COLUNAS))
    {
        printf("Navio diagonal 2 não cabe no tabuleiro.\n");
        exit(1);
	}

	// Posicinar os navios no tabuleiro
    int sobreposto = 0;
    for (int linhaIndice = 0; linhaIndice < TABULEIRO_QUANTIDADE_LINHAS; linhaIndice++)
    {
        for (int colunaIndice = 0; colunaIndice < TABULEIRO_QUANTIDADE_COLUNAS; colunaIndice++)
        {
            // Posicionamento do navio vertical
            if ((colunaIndice == NAVIO_VERTICAL_COLUNA_INICIAL) &&
                (linhaIndice >= NAVIO_VERTICAL_LINHA_INICIAL) &&
                (linhaIndice < (NAVIO_VERTICAL_LINHA_INICIAL + TAMANHO_NAVIO)))
            {
                if ((tabuleiro[linhaIndice][colunaIndice] != CARACTERE_AGUA) && (tabuleiro[linhaIndice][colunaIndice] != CARACTERE_HABILIDADE))
                {
                    sobreposto = 1;
                    break;
                }

                tabuleiro[linhaIndice][colunaIndice] = CARACTERE_NAVIO;
            }

            // Posicionamento do navio horizontal
            if ((linhaIndice == NAVIO_HORIZONTAL_LINHA_INICIAL) &&
                (colunaIndice >= NAVIO_HORIZONTAL_COLUNA_INICIAL) &&
                (colunaIndice < (NAVIO_HORIZONTAL_COLUNA_INICIAL + TAMANHO_NAVIO)))
            {
                if ((tabuleiro[linhaIndice][colunaIndice] != CARACTERE_AGUA) && (tabuleiro[linhaIndice][colunaIndice] != CARACTERE_HABILIDADE))
                {
                    sobreposto = 1;
                    break;
                }

                tabuleiro[linhaIndice][colunaIndice] = CARACTERE_NAVIO;
            }

			// Posicionamento do navio diagonal 1
            if ((linhaIndice >= NAVIO_DIAGONAL_1_LINHA_INICIAL) &&
                (linhaIndice < (NAVIO_DIAGONAL_1_LINHA_INICIAL + TAMANHO_NAVIO)) &&
                (colunaIndice >= NAVIO_DIAGONAL_1_COLUNA_INICIAL) &&
                (colunaIndice < (NAVIO_DIAGONAL_1_COLUNA_INICIAL + TAMANHO_NAVIO)) &&
                ((linhaIndice - NAVIO_DIAGONAL_1_LINHA_INICIAL) == (colunaIndice - NAVIO_DIAGONAL_1_COLUNA_INICIAL)))
            {
                if ((tabuleiro[linhaIndice][colunaIndice] != CARACTERE_AGUA) && (tabuleiro[linhaIndice][colunaIndice] != CARACTERE_HABILIDADE))
                {
                    sobreposto = 1;
                    break;
                }

                tabuleiro[linhaIndice][colunaIndice] = CARACTERE_NAVIO;
			}

			// Posicionamento do navio diagonal 2
            if ((linhaIndice >= NAVIO_DIAGONAL_2_LINHA_INICIAL) &&
                (linhaIndice < (NAVIO_DIAGONAL_2_LINHA_INICIAL + TAMANHO_NAVIO)) &&
                (colunaIndice >= NAVIO_DIAGONAL_2_COLUNA_INICIAL) &&
                (colunaIndice < (NAVIO_DIAGONAL_2_COLUNA_INICIAL + TAMANHO_NAVIO)) &&
                ((linhaIndice - NAVIO_DIAGONAL_2_LINHA_INICIAL) == (colunaIndice - NAVIO_DIAGONAL_2_COLUNA_INICIAL)))
            {
                if ((tabuleiro[linhaIndice][colunaIndice] != CARACTERE_AGUA) && (tabuleiro[linhaIndice][colunaIndice] != CARACTERE_HABILIDADE))
                {
                    sobreposto = 1;
                    break;
                }

                tabuleiro[linhaIndice][colunaIndice] = CARACTERE_NAVIO;
			}
        }

        // Validar sobreposição
        if (sobreposto)
        {
            printf("Navios sobrepostos no tabuleiro.\n");
            exit(1);
        }
    }

	// Aplicar habilidades
    aplicar_habilidade(
        tabuleiro,
        habilidadeCruz,
        HABILIDADE_CRUZ_LINHA_INICIAL,
        HABILIDADE_CRUZ_COLUNA_INICIAL);

    aplicar_habilidade(
        tabuleiro,
        habilidadeCone,
        HABILIDADE_CONE_LINHA_INICIAL,
        HABILIDADE_CONE_COLUNA_INICIAL);

    aplicar_habilidade(
        tabuleiro,
        habilidadeOctaedro,
        HABILIDADE_OCTAEDRO_LINHA_INICIAL,
        HABILIDADE_OCTAEDRO_COLUNA_INICIAL);

	// Exibir o tabuleiro
    printf("  0 1 2 3 4 5 6 7 8 9\n");
    for (int linhaIndice = 0; linhaIndice < TABULEIRO_QUANTIDADE_LINHAS; linhaIndice++)
    {
        printf("%d ", linhaIndice);
        for (int colunaIndice = 0; colunaIndice < TABULEIRO_QUANTIDADE_COLUNAS; colunaIndice++)
        {
			printf("%d ", tabuleiro[linhaIndice][colunaIndice]);
        }

        printf("\n");
    }

    exit(0);
}