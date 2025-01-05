inherit "/std/food";
 
int toxin_level = 0;
string crit_type = "none";
string crit_level = "X";
 
int is_potion_plant() { return 1; }
 
void set_toxin_level(int level) { toxin_level = level; }
int query_toxin_level() { return toxin_level; }
 
string query_crit_type() { return crit_type; }
string query_crit_level() { return crit_level; }
