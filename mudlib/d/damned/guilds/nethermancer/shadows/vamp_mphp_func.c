int vampiric_func(int dice, object who) {
  int res, i, mult;
  int sides = 6;
  object wield = previous_object();

  res = 0;
  if(dice < 0) {
    mult = -1;
    dice *= -1;
  } else
    mult = 1;
  for(i=1; i<=dice; i++) res += 1+random(sides);
  res *= mult;
who->add_mp(-1 * res/15);
who->add_hp(-1 * res/8);
  wield = wield->query_wielded();
  if(wield) {
wield->add_mp(res/15);
wield->add_hp(res/8);
    message("info", "%^MAGENTA%^%^BOLD%^The blade drains %^RESET%^"+
"%^CYAN%^"+sprintf("%d mp and %d hp", res/15, res/8)+"%^RESET%^%^MAGENTA%^"+
	    "%^BOLD%^ from your victim!", wield);
  }
  return 0;
}

