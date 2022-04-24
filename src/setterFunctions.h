void setOscilATableMono(int switchPosition){
    switch(switchPosition){
         case 0: 
            oscilA.setTable(SAW8192_DATA);
            break;
        case 1:
            oscilA.setTable(SMOOTHSQUARE8192_DATA);
            break;
        case 2: 
            oscilA.setTable(SIN8192_DATA);
            break;
    }
}

void setOscilBTableMono(int switchPosition){
    switch(switchPosition){
        case 0: 
            oscilB.setTable(SAW8192_DATA);
            break;
        case 1:
            oscilB.setTable(PIANO8192_DATA);
            break;
        case 2: 
            oscilB.setTable(SLUMBER8192_DATA);
            break;
    }
}

void setOscilCTableMono(int switchPosition){
    switch(switchPosition){
        case 0: 
            oscilC.setTable(SAW8192_DATA);
            break;
        case 1:
            oscilC.setTable(CRUNCH8192_DATA);
            break;
        case 2: 
            oscilC.setTable(SLUMBER8192_DATA);
            break;
    }
}

void setOscilDTableMono(int switchPosition){
    switch(switchPosition){
        case 0: 
            oscilD.setTable(SAW8192_DATA);
            break;
        case 1:
            oscilD.setTable(WHITENOISE8192_DATA);
            break;
        case 2: 
            oscilD.setTable(CHUM9_DATA);
            break;
    }
}

void setOscilATablePoly(int switchPosition1, int switchPosition2){
    switch(switchPosition1){
        case 0: 
            switch(switchPosition2){
                case 0: 
                    oscilA.setTable(SAW8192_DATA);
                    break;
                case 1: 
                    oscilA.setTable(SMOOTHSQUARE8192_DATA);
                    break;
                case 2: 
                    oscilA.setTable(SIN8192_DATA);
                    break;
            }
            break;
        case 1: 
            switch(switchPosition2){
                case 0: 
                    oscilA.setTable(PIANO8192_DATA);
                    break;
                case 1: 
                    oscilA.setTable(CRUNCH8192_DATA);
                    break;
                case 2: 
                    oscilA.setTable(SLUMBER8192_DATA);
                    break;
            }
            break;
        case 2: 
            switch(switchPosition2){
                case 0: 
                    oscilA.setTable(SLUMBER8192_DATA);
                    break;
                case 1: 
                    oscilA.setTable(SLUMBER8192_DATA);
                    break;
                case 2: 
                    oscilA.setTable(SLUMBER8192_DATA);
                    break;
            }
            break;
    }
}

void setOscilBTablePoly(int switchPosition1, int switchPosition2){
    switch(switchPosition1){
        case 0: 
            switch(switchPosition2){
                case 0: 
                    oscilB.setTable(SAW8192_DATA);
                    break;
                case 1: 
                    oscilB.setTable(SMOOTHSQUARE8192_DATA);
                    break;
                case 2: 
                    oscilB.setTable(SIN8192_DATA);
                    break;
            }
            break;
        case 1: 
            switch(switchPosition2){
                case 0: 
                    oscilB.setTable(PIANO8192_DATA);
                    break;
                case 1: 
                    oscilB.setTable(CRUNCH8192_DATA);
                    break;
                case 2: 
                    oscilB.setTable(SLUMBER8192_DATA);
                    break;
            }
            break;
        case 2: 
            switch(switchPosition2){
                case 0: 
                    oscilB.setTable(SLUMBER8192_DATA);
                    break;
                case 1: 
                    oscilB.setTable(SLUMBER8192_DATA);
                    break;
                case 2: 
                    oscilB.setTable(SLUMBER8192_DATA);
                    break;
            }
            break;
    }
}

void setOscilCTablePoly(int switchPosition1, int switchPosition2){
    switch(switchPosition1){
        case 0: 
            switch(switchPosition2){
                case 0: 
                    oscilC.setTable(SAW8192_DATA);
                    break;
                case 1: 
                    oscilC.setTable(SMOOTHSQUARE8192_DATA);
                    break;
                case 2: 
                    oscilC.setTable(SIN8192_DATA);
                    break;
            }
            break;
        case 1: 
            switch(switchPosition2){
                case 0: 
                    oscilC.setTable(PIANO8192_DATA);
                    break;
                case 1: 
                    oscilC.setTable(CRUNCH8192_DATA);
                    break;
                case 2: 
                    oscilC.setTable(SLUMBER8192_DATA);
                    break;
            }
            break;
        case 2: 
            switch(switchPosition2){
                case 0: 
                    oscilC.setTable(SLUMBER8192_DATA);
                    break;
                case 1: 
                    oscilC.setTable(SLUMBER8192_DATA);
                    break;
                case 2: 
                    oscilC.setTable(SLUMBER8192_DATA);
                    break;
            }
            break;
    }
}

void setOscilDTablePoly(int switchPosition1, int switchPosition2){
    switch(switchPosition1){
        case 0: 
            switch(switchPosition2){
                case 0: 
                    oscilD.setTable(SAW8192_DATA);
                    break;
                case 1: 
                    oscilD.setTable(SMOOTHSQUARE8192_DATA);
                    break;
                case 2: 
                    oscilD.setTable(SIN8192_DATA);
                    break;
            }
            break;
        case 1: 
            switch(switchPosition2){
                case 0: 
                    oscilD.setTable(PIANO8192_DATA);
                    break;
                case 1: 
                    oscilD.setTable(CRUNCH8192_DATA);
                    break;
                case 2: 
                    oscilD.setTable(SLUMBER8192_DATA);
                    break;
            }
            break;
        case 2: 
            switch(switchPosition2){
                case 0: 
                    oscilD.setTable(SLUMBER8192_DATA);
                    break;
                case 1: 
                    oscilD.setTable(SLUMBER8192_DATA);
                    break;
                case 2: 
                    oscilD.setTable(SLUMBER8192_DATA);
                    break;
            }
            break;
    }
}

void setLfoTable(int switchPosition){
    switch(switchPosition){
         case 0: 
            lfo.setTable(SAWDOWN2048_DATA);
            break;
        case 1:
            lfo.setTable(SQUARE_NO_ALIAS_2048_DATA);
            break;
        case 2: 
            lfo.setTable(SIN2048_DATA);
            break;
    }
}