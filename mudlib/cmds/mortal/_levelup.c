#include <daemons.h>
#include <security.h>

#define STATS ({ "strength", "constitution", "intelligence", "dexterity", "wisdom", "charisma" })
#define ABRVS (["str": "strength", "con": "constitution", "int": "intelligence", "dex": "dexterity", "wis": "wisdom", "cha": "charisma"])

int cmd_levelup(string stat) {
    int level, stat_points, max_stat_points, current_stat;
    string full_stat;
    string lower_stat;

    // Ensure the player is not a wizard
    if (wizardp(this_player())) {
        write("Wizards don't need to level up in this way!");
        return 1;
    }

    // Get current level and stat points
    level = this_player()->query_level();
    stat_points = this_player()->query_property("stat_points");

    // If stat_points is undefined, initialize it
    if (!stat_points) {
        stat_points = 0; // Default to 0 if not set
    }

    max_stat_points = level;  // Max points equal to the current level

    // If the player has no stat points
    if (stat_points <= 0) {
        write("You have no more stat points to spend.");
        return 1;
    }

    // Check if stat is provided
    if (!stat || stat == "") {
        write("Invalid stat. Choose from: " + implode(STATS, ", ") + ". You currently have %^YELLOW%^" + stat_points + "%^RESET%^ stat points");
        return 1;
    }

    // Check for abbreviation and map to full stat name
    lower_stat = lower_case(stat);
    if (undefinedp(ABRVS[lower_stat])) {
        // Validate the stat provided
        if (member_array(lower_stat, STATS) == -1) {
            write("Invalid stat. Choose from: " + implode(STATS, ", ") + ". You currently have %^YELLOW%^" + stat_points + "%^RESET%^ stat points");
            return 1;
        } else {
            full_stat = lower_stat; // Use the full stat name
        }
    } else {
        full_stat = ABRVS[lower_stat]; // Get full stat name from abbreviation
    }

    // Spend a stat point
    this_player()->set_property("stat_points", stat_points - 1);

    // Increase the chosen stat
    current_stat = this_player()->query_stats(full_stat);
    this_player()->set_stats(full_stat, current_stat + 1);

    write("You have increased your " + full_stat + " by 1. You now have " + (stat_points - 1) + " stat points left.");
    return 1;
}

int help() {
    message("help",
    "Usage example: 'levelup str'\n"
    "You may use this command to level up stats using abbreviations like 'str' for strength.", this_player());
    return 1;
}
