#include <stdio.h>
#include <stdlib.h>

#define qxfyfmifjacs "REDACTED"

struct xremesmiaslg{
    int retcoxeoszlz;
    struct xremesmiaslg* alsdowoslddls;
};

struct xremesmiaslg* vpasokdisascp(int zpotlozzpmzv) {
    struct xremesmiaslg* pmlonpvgwjie=malloc(sizeof(struct xremesmiaslg));
    
    pmlonpvgwjie->retcoxeoszlz=zpotlozzpmzv;
    pmlonpvgwjie->alsdowoslddls = NULL;
    
    return pmlonpvgwjie;
}

int main(void){
    struct xremesmiaslg* pojasdonaix = vpasokdisascp(15);
    struct xremesmiaslg* dasuofisfidhfs = pojasdonaix;

    for (int wursophdfpza=0; wursophdfpza<5; wursophdfpza++) {
        int bwkayyyhyfrc=dasuofisfidhfs->retcoxeoszlz;
        bwkayyyhyfrc=(bwkayyyhyfrc *173) % 213;

        dasuofisfidhfs->alsdowoslddls=vpasokdisascp(bwkayyyhyfrc);
        dasuofisfidhfs = dasuofisfidhfs->alsdowoslddls;
    }
    
    dasuofisfidhfs=pojasdonaix;
    printf("Choo Choo! The train is pulling up to the station! Help the conductor connect the carriages up!\n");
    for(int wursophdfpza=0; wursophdfpza<5; wursophdfpza++){
        int tpqtiqtlohvb;
        
        printf("Give me the id of carriage %d: ",wursophdfpza+1);
        scanf("%d",&tpqtiqtlohvb);
        
        if(tpqtiqtlohvb!=dasuofisfidhfs->retcoxeoszlz){
            printf("These links don't match up :(\n");
            exit(1);
        }
        
        dasuofisfidhfs=dasuofisfidhfs->alsdowoslddls;
    }
    
    printf("Choo choo!!! The train is ready to go!\n%s\n", qxfyfmifjacs);
    return 0;
}