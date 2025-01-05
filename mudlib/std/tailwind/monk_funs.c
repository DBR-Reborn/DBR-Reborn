//This function returns true if the argument passed is wearing
//armour thats heavier than cloth.
int monk_has_heavy_armour(object monk)
{
  object *monk_inv;
  int foo;
  string *armour;

  monk_inv = all_inventory(monk);
  foo = sizeof(monk_inv);
  while(foo--)
  {
    if(monk_inv[foo] -> query_worn())
    {
      armour = explode(monk_inv[foo]->query_material(), "/");
      if(armour[0] == "metal" || armour[0] == "wood")
        return 1;
    }  
  }
  return 0;
}

//This function checks to see if the person has at least two legs
//and two arms.  Needed to use styles 
int monk_has_limbs(object player)
{
  string* limbs;
  int arms = 0;
  int legs = 0;
  int foo;
  string side, limb;

  limbs = player->query_limbs();
  if(!limbs || !(foo = sizeof(limbs))) 
    return 0;

  while(foo--)
  {
    sscanf(limbs[foo], "%s %s", side, limb);
    if(limb == "leg" || limb == "foreleg" 
       && !player->query_crippled(limbs[foo]))
      legs++;
    if(limb == "arm" || limb == "forearm" 
       && !player->query_crippled(limbs[foo]))
      arms++;
  }
  if(arms > 1 && legs > 1)
    return 1;
  return 0;
}
