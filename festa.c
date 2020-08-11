#include <stdio.h>
#include <assert.h>

#define MAXM 100000

int invita(int N, int M, int conoscenzeA[], int conoscenzeB[]) {
    // Mettete qui il codice della soluzione
    int result=0;
    int partecipanti[N];
    for(int i=0;i<N;i++)
        partecipanti[i]=0;
    for(int i=0;i<M;i++){
        partecipanti[conoscenzeA[i]]++;
        partecipanti[conoscenzeB[i]]++;
    }
    for(int j=0;j<M/N;j++){
        for(int i=0;i<M;i++){
            if((partecipanti[conoscenzeA[i]]<2)||(partecipanti[conoscenzeB[i]]<2)){
                partecipanti[conoscenzeB[i]]--;
                partecipanti[conoscenzeA[i]]--;
            }
        }
    }
    for(int i=0;i<N;i++){
        if(partecipanti[i]>1)
            result++;
    }

    return result;
}


int conoscenzeA[MAXM], conoscenzeB[MAXM];

int main() {
    FILE *fr, *fw;
    int N, M, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d%d", &N, &M));
    for(i=0; i<M; i++)
        assert(2 == fscanf(fr, "%d%d", &conoscenzeA[i], &conoscenzeB[i]));

    fprintf(fw, "%d\n", invita(N, M, conoscenzeA, conoscenzeB));
    fclose(fr);
    fclose(fw);
    return 0;
}
