#include <std.h>
 
inherit DAEMON;
 
int cmd_exp(string arg) {
    string mind;
    int level, nlevel, exp, nexp;
    mixed lexp;

    level=this_player()->query_level();
    nlevel=level+1;
    exp=this_player()->query_exp();
    nexp="/adm/daemon/advance_d"->get_exp(nlevel);
    lexp=nexp-exp;
            switch((int)this_player()->percent_buffer()) {
            case 0..5: mind = "clear"; break;
            case 6..25: mind = "almost clear"; break;
            case 26..50: mind = "slightly fuzzy"; break;
            case 51..75: mind = "clouded"; break;
            case 76..89: mind = "very fuzzy"; break;
            case 90..98: mind = "%^MAGENTA%^full of facts%^RESET%^"; break;
            case 99..110: mind = "%^GREEN%^OVER FOF%^RESET%^"; break;
            case 111..200: mind = "%^RED%^OVER FOF%^RESET%^"; break;
            case 201..1100: mind = "%^WHITE%^OVER FOF%^RESET%^"; break;
            default: mind = "clear"; break;
            }
 if(!arg) {
  write("%^BOLD%^CYAN%^exp: %^BOLD%^WHITE%^"+lexp+"%^RESET%^");
  return 1;
 }
  else write("Unknown arguement: "+ arg);
  return 1;
}

 
void help() {
    write("Syntax: <statusexp>\n\n"+
        "Show your experience\n"
        "See also: score\n"
    );
}
