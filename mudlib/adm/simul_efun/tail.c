int tail(string fname) {
    string str;
    int offset = file_size(fname);

    if (offset < 0)
    return 0;
    
    offset -= 54 * 20;
    if (offset < 0) offset = 0;
    str = read_bytes(fname, offset, 1080);
    if (!str) return 0;
    if (offset) str = str[strsrch(str, "\n")+1..];
    write(str);

    return 1;
}

