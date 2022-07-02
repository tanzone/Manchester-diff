#include "ManchesterDiff.h"

void Codifica_ManchesterDifferenziato(char* szOnde)
{
    StampaLegenda(szOnde);

    printf("\n+ ");
    LetturaStringa(szOnde, SOPRA);

    printf("\n0 ");
    LetturaStringa(szOnde, SOTTO);
}

/**
*STAMPO TUTTO IL TITOLO
**/
void StampaLegenda(char* szonde)
{
    int i;

    printf("Codifica Manchester Differenziato\n");

    for(i = 0; i < strlen(szonde); i++)
        printf("   %c", szonde[i]);
}

/**
*LETTURA DELLA STRINGA
**/
void LetturaStringa(char* szOnde, int linea)
{
    int i;
    int livello = BASSO;

    for(i = 0; i < DIM; i++)
    {
        if(linea == SOPRA)
        {
            livello = BitOndaSopra(livello, szOnde[i]);
            ControlloSopra(szOnde, i, livello);

        }
        else if(linea == SOTTO)
        {
            livello = BitOndaSotto(livello, szOnde[i]);
            ControlloSotto(szOnde, i, livello);
        }
    }
}

/**
*STAMPA A SECONDA DELLA CONDIZIONE PER LA LINEA SOTTO
**/
int BitOndaSotto(int come, char valore)
{
    switch(come)
    {
        case ALTO:
            if(valore == '0')
            {
                putchar(196);
                putchar(217);
                putchar(0);
                come = ALTO;
            }

            if(valore == '1')
            {
                putchar(0);
                putchar(192);
                putchar(196);
                come = BASSO;
            }
            break;

            case BASSO:
                if(valore == '0')
                {
                    putchar(0);
                    putchar(192);
                    putchar(196);
                    come = BASSO;
                }

                if(valore == '1')
                {
                    putchar(196);
                    putchar(217);
                    putchar(0);
                    come = ALTO;
                }
                break;
    }
return come;
}


/**
*STAMPA A SECONDA DELLA CONDIZIONE PER LA LINEA SOPRA
**/
int BitOndaSopra(int come, char valore)
{
    switch(come)
        {

        case ALTO:
            if(valore == '0')
            {
                putchar(0);
                putchar(218);
                putchar(196);
                come = ALTO;
            }

            if(valore == '1')
            {
                putchar(196);
                putchar(191);
                putchar(0);
                come = BASSO;
            }
            break;

        case BASSO:
            if(valore == '0')
            {
                putchar(196);
                putchar(191);
                putchar(0);
                come = BASSO;
            }

            if(valore == '1')
            {
                putchar(0);
                putchar(218);
                putchar(196);
                come = ALTO;
            }
            break;
    }
return come;
}


/**
*CONTROLLO PER LA TRANSIZIONE A MEZZO BIT SOPRA
**/
void ControlloSopra(char* szOnde, int i, int come)
{
    if( ( szOnde[i] == '0' && szOnde[i+1] == '0') || ( szOnde[i] == '1' && szOnde[i+1] == '0') )
    {
        if(come == SOPRA)
            putchar(191);

        else if(come == SOTTO)
            putchar(218);
    }
    else if(come == SOPRA)
        putchar(196);

    else
        putchar(0);
}

/**
*CONTROLLO PER LA TRANSIZIONE A MEZZO BIT SOTTO
**/
void ControlloSotto(char* szOnde, int i, int come)
{
    if((szOnde[i] == '0' && szOnde[i+1] == '0') || (szOnde[i] == '1' && szOnde[i+1] == '0'))
    {
        if(come == SOPRA)
            putchar(192);

        else if(come == SOTTO)
            putchar(217);
    }
    else if(come == SOTTO)
        putchar(196);

    else
        putchar(0);
}
