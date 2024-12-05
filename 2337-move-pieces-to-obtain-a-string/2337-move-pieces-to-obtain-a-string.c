bool canChange(char* start, char* target) {
    int len=strlen(start);
    int sidx=0;
    int tidx=0;
    while(sidx<len || tidx<len){
        while( sidx<len && start[sidx]=='_') sidx++;
        while( tidx<len && target[tidx]=='_') tidx++;
        if( (start[sidx]!=target[tidx]) || (start[sidx]=='L' && sidx<tidx ) || (start[sidx]=='R' && sidx>tidx ) ) return false;
        sidx++;
        tidx++;

    }
    return true;
}