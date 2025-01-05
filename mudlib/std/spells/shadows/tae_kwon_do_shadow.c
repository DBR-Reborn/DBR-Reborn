// Te 'style' for Warrior Monks
#include "/wizards/tailwind/tailwind.h";
#include "/wizards/tailwind/monk.h";

inherit SHADOWDIR+"style_shadow";

string* monk_messages(object from, object at, int which)
{
  string me, them, other;  // message strings
  string* ret;             // return

  switch(which)
  {
    case 0..30:
      me = "You reach out quickly and bap "+AQCN+" with your open palm.";
      them = FQCN+" reaches out quickly and baps you with his open palm.";
      other = FQCN+" reaches out quckly and baps "+AQCN+" with his open palm."; 
      break;
    case 31..40:
      me = "You smack "+AQCN+"'s head, making him see stars.";
      them = FQCN+" smacks your head, making you see stars";
      other = FQCN+" smacks "+AQCN+" in the head, making him see stars.";
      break;
    case 41..50:
      me = "You shove your open hand into "+AQCN+"'s stomach, making "+
            AQOB+" gasp for breath.";
      them = FQCN+" shoves "+FQPO+" hand into your stomach, making you "+
             "gasp for breath.";
      other = FQCN+" shoves "+FQPO+" fist into "+AQCN+"'s stomach "+
              "making "+AQOB+" gasp for breath.";
      break;
    case 51..60:
      me = "Moving in a blur, you impact "+AQCN+" with your hands "+
           "repeatedly.";
      them = "Moving in a blur, "+FQCN+" impacts you with "+FQPO+
             " hands repeatedly.";
      other = FQCN+" moves in a blur, impacting "+AQCN+" with "+FQPO+
              " hands repeatedly.";
      break;
    case 61..70:
      me = "Adrenaline beginning to surge, you smash "+AQCN+" with fury";
      them = FQCN+"'s adrenaline begins to surge, and "+FQSU+" smashes "+
             "you with fury.";
      other = FQCN+"'s adrenaline begins to surge, and "+FQSU+" smashes "+
              AQCN+" with fury.";
      break;
    case 71..80:
      me = "You crush "+AQCN+"'s face, flattening "+AQPO+" nose.";
      them = FQCN+" crushes your face, flattening your nose.";
      other = FQCN+" crushes "+AQCN+"'s face, flattening "+AQPO+" nose.";
      break;
    case 81..90: 
      me = "You slam your hands into "+AQCN+" repeatedly, cracking bones."; 
      them = FQCN+ "slams her hands into you repeatedly, cracking your bones.";
      other = FQCN+ "slams +FQPO+ hands into "+AQCN+
		" repeatedly, cracking "+AQPO+" bones.";
      break;
    case 91..100:
      me = "Worked into a fury, you crush "+AQCN+" with lightning "+
           "fast strikes.";
      them = "Worked into a fury, "+FQCN+" crushes you with lightning "+
             "fast strikes.";
      other = "Worked into a fury, "+FQCN+" crushes "+AQCN+" with lightning "+
              "fast strikes.";
      break;
    case 101..110:
      me = "Your hand slams into "+AQCN+"'s stomach, making blood "+
           "spew from "+AQPO+" mouth.";
      them = AQCN+"'s hand slams into your stomach, making blood "+
             "spew from your mouth.";
      other = FQCN+"'s hand slams into "+AQCN+"'s stomach, making blood "+
              "spew from "+AQPO+" mouth.";
      break;
    case 111..120:
      me = "Your punishing fists beat "+AQCN+" repeatedly, so fast "+
           "that skin flies everywhere.";
      them = FQCN+"'s punishing fists beat you repeatedly, so fast "+
             "that skin flies everywhere.";
      other = FQCN+"'s punishing fists beat "+AQCN+" repeatedly, so fast "+
              "that skin flies everywhere.";
      break;
    case 121..130:
      me = "Your deadly assault leaves "+AQCN+" a shaking puddle of "+
           "broken bones!";
      them = FQCN+"'s deadly assault leaves you a shaking puddle of "+
             "broken bones!";
      other = FQCN+"'s deadly assault leaves "+AQCN+" a shaking puddle of "+
              "broken bones!";
      break;
    case 131..140:
      me = "Moving faster than seems possible, you land hit after hit "+
           "on "+AQCN+", shredding skin and breaking bones!";
      them = "Moving faster than seems possible, "+FQCN+" lands hit after "+
             "hit on you, shredding skin and breaking bones!";
      other = "Moving faster than seems possible, "+FQCN+" lands hit after "+
              "hit on "+AQCN+", shredding skin and breaking bones!";
      break;
    case 141..1000:
      me = "You smash your open palm into "+AQCN+"'s chest, splitting "+
           "it open.  Organs fly everywhere!";
      them = FQCN+" smashes "+FQPO+" open palm into your chest, splitting "+
             "it open.  Organs fly everwhere!";
      other = FQCN+" smashes "+FQPO+" open palm into "+AQCN+"'s chest, "+
              "splitting it open.  Organs fly everwhere!";
      break;
  }
  ret = ({ HC+me+RC, HC+them+RC, HC+other+RC });
  return ret;
}

string* monk_crit_types()
{ return ({ "impact", "crushing", "strike" }); }
  
