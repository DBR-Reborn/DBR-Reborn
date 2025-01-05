#include <def.h>

//This functions checks a players skill + a mod, + random roll vs 100.
//if the sum of those 3 is greater than 100, skill succeeds and it returns 1
//if between 0 and 100 then skill fails and returns 0, if less than 0 then
//skill critically fails and it returns -1. The random roll is open ended
//in positive and negative directoin, so with luck anyone can fail or
//succeed no matter what thier skills are like.
int skill_check(string skill, int bonus)
{
int modifier, pskill, rand, is_minus, tot_rand;
  if(bonus)
    modifier = bonus;
  pskill = TP->query_skill(skill);
  is_minus = 0;
  rand = random(100);
  tot_rand = rand;
  if(rand < 5)
  {
    is_minus = 1;
    rand = random(100);
    tot_rand += rand;
  }
  while(rand > 95)
  {
    rand = random(100);
    tot_rand += rand;
  }
  if(is_minus) tot_rand *= -1;
  tot_rand = tot_rand + pskill + modifier;
  if(tot_rand > 100)
    return 1;
  else if((tot_rand >= 0) || (tot_rand <= 100))
    return 0;
  else
    return -1;
}

//This function generates open ended damage based on the given base_dam.
//Theres a 5% chance for reroll which is added to the damage, and 5% based
//on reroll etc etc. Please make base_dam a min of 20.
int gen_rand_damage(int base_dam)
{
int threshold, fuckem, rand;

  threshold = (base_dam / 100) * 5;
  rand = random(base_dam);
  fuckem = rand;
  while(rand >= (base_dam - threshold))
  {
    rand = random(base_dam);
    fuckem += rand;
  }
  return(fuckem * -1);
}
