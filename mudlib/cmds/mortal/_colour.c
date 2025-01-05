/*  /cmds/mortal/_colours.c
 *  Made for DarkeMUD
 *  Created by Geldron 031396
 *  Copyright (c) 1996, DarkeMUD
 *  Do not rmeove this header
 */


inherit DAEMON;

int cmd_colour(string arg) {
    if(arg) {
	message("colours_syntax", syntax("colours"), TP);
	return 1;
    }
    write("%^RED%^" + repeat_string("-=", 14) + "] %^GREEN%^Valid Colours %^RED%^[" +
      repeat_string("=-", 14) + "%^RESET%^");
            write(  "%^RED%^RED\t%%^^RED%%^^\t\t%^BOLD%^%%^^BOLD%%^^%%^^RED%%^^%^RESET%^\n"
            "%^GREEN%^GREEN\t%%^^GREEN%%^^\t%^BOLD%^%%^^BOLD%%^^%%^^GREEN%%^^%^RESET%^\n"
            "%^ORANGE%^ORANGE\t%%^^ORANGE%%^^\t%^BOLD%^%%^^BOLD%%^^%%^^ORANGE%%^^%^RESET%^\n"
            "%^YELLOW%^YELLOW %%^^YELLOW%%^^\t%^BOLD%^%%^^BOLD%%^^%%^^YELLOW%%^^%^RESET%^\n"
            "%^BLUE%^BLUE\t%%^^BLUE%%^^\t%^BOLD%^%%^^BOLD%%^^%%^^BLUE%%^^%^RESET%^\n"
            "%^CYAN%^CYAN\t%%^^CYAN%%^^\t%^BOLD%^%%^^BOLD%%^^%%^^CYAN%%^^%^RESET%^\n"
            "%^MAGENTA%^MAGENTA %%^^MAGENTA%%^^\t%^BOLD%^%%^^BOLD%%^^%%^^MAGENTA%%^^%^RESET%^\n"
            "%^BLACK%^BLACK\t%%^^BLACK%%^^\t%^BOLD%^%%^^BOLD%%^^%%^^BLACK%%^^%^RESET%^\n"
            "%^WHITE%^WHITE\t%%^^WHITE%%^^\t%^BOLD%^%%^^BOLD%%^^%%^^WHITE%%^^%^RESET%^\n"
            "%^BLACK%^B_RED%^B_RED\t\t%%^^B_RED%%^^%^RESET%^\n"
            "%^BLACK%^B_GREEN%^B_GREEN\t\t%%^^B_GREEN%%^^%^RESET%^\n"
            "%^BLACK%^B_ORANGE%^B_ORANGE\t%%^^B_ORANGE%%^^%^RESET%^\n"
            "%^BLACK%^B_YELLOW%^B_YELLOW\t%%^^B_YELLOW%%^^%^RESET%^\n"
            "%^BLACK%^B_BLUE%^B_BLUE\t\t%%^^B_BLUE%%^^%^RESET%^\n"
            "%^BLACK%^B_CYAN%^B_CYAN\t\t%%^^B_CYAN%%^^%^RESET%^\n"
            "%^BLACK%^B_MAGENTA%^B_MAGENTA\t%%^^B_MAGENTA%%^^%^RESET%^\n"
            "%^BOLD%^BLACK%^B_BLACK%^B_BLACK\t\t%%^^B_BLACK%%^^%^RESET%^\n"
            "%^BLACK%^B_WHITE%^B_WHITE\t\t%%^^B_WHITE%%^^%^RESET%^\n"
            );
    write("%^RED%^-" + repeat_string("=-", 36) + "%^RESET%^");
    return 1;
}

void help() {
    message("colours_help", syntax("colour") + "\n\n"
      "Lists all possible colour settings for the 'colour' command.\n\n"
      "also see 'help colours' or 'help xterm-256'", TP);
}
