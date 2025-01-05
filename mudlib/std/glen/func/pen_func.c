int pen_func(int chance, object who) {
    int i;
    object ob;
    mapping wcs;
    string  *keyss;
    int     damage = 0;
    object wielder;
    object wield;
    wield   = previous_object();
    wielder = wield->query_wielded();

    if(random(100) > chance)
	return 0;

    if(!wield)
	return 0;

    wcs = wield->query_all_wc();
    keyss = keys(wcs);

    for(i = 0; i < sizeof(keyss); i++)
	damage += wcs[keyss[i]] / 3;
    if(wizardp(wielder))
	message("info", "damage " + damage, wielder);

    who->do_damage(who->return_target_limb(), damage);

    message("info", 
      "%^BOLD%^" + "%^MAGENTA%^" +
      "Your weapon penetrates your opponent."
      ,wielder);
    message("info", 
      "%^BOLD%^" + "%^RED%^" +
      "The attack penetrates your armour, that hurts!"
      ,who);

    return 0;
}

