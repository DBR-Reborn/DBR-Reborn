// _affects.c
// Coded by Thrace Merin for Daybreak Ridge
// 07/27/01
// Do not remove this header.

int cmd_affects(string str) {
    string *list, temp;
    int i;


    if(temp = this_player()->query_shadows()) {
        list = explode(temp, ",");
    }
    else list = ({ "nothing" });

    list = filter_array(list, "filter_generic", this_object());
    for(i = 0;i < sizeof(list); i++) list[i] = capitalize(lower_case(list[i]));
    list = sort_array(list, "alphabetize", this_object());
    message("info", "%^WHITE%^%^BOLD%^Currently Affecting you:\n%^RED%^"+repeat_string("-", 65),this_player());
    this_player()->more(explode(format_page(list, 2),"\n"));
    message("info", "%^RED%^%^BOLD%^"+repeat_string("-", 65),this_player());

write("Shadows: " + temp + "\n");
    return 1;
}


void help() {
    message("help","This command allows you to see what spells are currently affecting you.\nSyntax: affects.", this_player());
}

int filter_generic(string str) {
    if(str == "generic") return 0;
    else return 1;
}

int alphabetize(string first, string next) {
    return strcmp(explode(first," ")[0],explode(next," ")[0]);
}
