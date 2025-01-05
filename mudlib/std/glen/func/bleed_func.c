int bleed_func(int chance, object who) {
    int i;
    object ob;
    object wield = previous_object();
    wield = wield->query_wielded();

    if(random(100) < chance)
	return 0;

    if(wield) {
	message("info", 
	  "%^BOLD%^" + "%^MAGENTA%^" +
	  "Your weapon causes your opponent to bleed."
	  ,wield);
	message("info", 
	  "%^BOLD%^" + "%^RED%^" +
	  "The attack causes you to begin bleeding!"
	  ,who);
	ob = new("/std/spells/shadows/bleed_shadow");
	ob->set_bleed_rate(5);
	ob->set_bleeding_interval(3);
	ob->start_shadow(who, 40, 
	  "%^BOLD%^" + "%^BLUE%^" +
	  "Your wounds stop bleeding.");
    }
    return 0;
}

