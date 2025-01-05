inherit "/std/skills/skill";

string wc_str(int wc);
int abs(int num);

void create() {
    ::create();
    set_stat("intelligence");
    set_dev_cost(17);
    set_fast_dev_cost(55);
    set_property("no target", 1);
}

void info() {
message("help",
"This skill may be used to compare two armours or weapons to see which will "+
"fare better in combat.  Use it with the following format:\n"+
"	use compare at sword and mace\n"+
"	use compare at helmet and breastplate\n\n"
"Tlny note added\n"
"You can also compare the same piece of armour or weapon to see it's damage or armour if your skill is high enough",
this_player());
}


string wc_str(int wc) {
  switch(wc) {
case -100..0: return "terrible";
	case 1..5: return "1-5";
	case 6..10: return "6-10";
	case 11..15: return "11-15";
	case 16..20: return "16-20";
    case 21..25: return "21-25";
	case 26..30: return "26-30";
	case 31..35: return "31-35";
	case 36..40: return "36-40";
  	case 41..45: return "41-45";
	case 46..50: return "46-50";
	case 51..55: return "51-55";
	case 56..60: return "56-60";
	case 61..65: return "61-65";
	case 66..70: return "66-70";
	case 71..75: return "71-75";
	case 76..80: return "76-80";	
	case 81..85: return "81-85";
	case 86..90: return "86-90";  
	case 91..95: return "91-95";
	case 96..100: return "96-100";

	case 101..105: return "101-105";
	case 106..110: return "106-110";
	case 111..115: return "111-115";
	case 116..120: return "116-120";
	case 121..125: return "121-125";
	case 126..130: return "126-130";
	case 131..135: return "131-135";
	case 136..140: return "136-140";
	case 141..145: return "141-145";
	case 146..150: return "146-150";
	case 151..155: return "151-155";
	case 156..160: return "156-160";
	case 161..165: return "161-165";
	case 166..170: return "166-170";
	case 171..175: return "171-175";
	case 176..180: return "176-180";
	case 181..185: return "181-185";
	case 186..190: return "186-190";
	case 191..195: return "191-195";
	case 196..200: return "196-200";

	case 201..205: return "201-205";
	case 206..210: return "206-210";
	case 211..215: return "211-215";
	case 216..220: return "216-220";
	case 221..225: return "221-225";
	case 226..230: return "226-230";
	case 231..235: return "231-235";
	case 236..240: return "236-240";
	case 241..245: return "241-245";
	case 246..250: return "246-250";
	case 251..255: return "251-255";
	case 256..260: return "256-260";
	case 261..265: return "261-265";
	case 266..270: return "266-270";
	case 271..275: return "271-275";
	case 276..280: return "276-280";
	case 281..285: return "281-285";
	case 286..290: return "286-290";
	case 291..295: return "291-295";
	case 296..300: return "296-300";
	
	case 301..305: return "301-305";
	case 306..310: return "306-310";
	case 311..315: return "311-315";
	case 316..320: return "316-320";
	case 321..325: return "321-325";
	case 326..330: return "326-330";
	case 331..335: return "331-335";
	case 336..340: return "336-340";
	case 341..345: return "341-345";
	case 346..350: return "346-350";
	case 351..355: return "351-355";
	case 356..360: return "356-360";
	case 361..365: return "361-365";
	case 366..370: return "366-370";
	case 371..375: return "371-375";
	case 376..380: return "376-380";
	case 381..385: return "381-385";
	case 386..390: return "386-390";
	case 391..395: return "391-395";
	case 396..400: return "396-400";
	
	case 401..405: return "401-405";
	case 406..410: return "406-410";
	case 411..415: return "411-415";
	case 416..420: return "416-420";
	case 421..425: return "421-425";
	case 426..430: return "426-430";
	case 431..435: return "431-435";
	case 436..440: return "436-440";
	case 441..445: return "441-445";
	case 446..450: return "446-450";
	case 451..455: return "451-455";
	case 456..460: return "456-460";
	case 461..465: return "461-465";
	case 466..470: return "466-470";
	case 471..475: return "471-475";
	case 476..480: return "476-480";
	case 481..485: return "481-485";
	case 486..490: return "486-490";
	case 491..495: return "491-495";
	case 496..500: return "496-500";
	
	case 501..505: return "501-505";
	case 506..510: return "506-510";
	case 511..515: return "511-515";
	case 516..520: return "516-520";
	case 521..525: return "521-525";
	case 526..530: return "526-530";
	case 531..535: return "531-535";
	case 536..540: return "536-540";
	case 541..545: return "541-545";
	case 546..550: return "546-550";
	case 551..555: return "551-555";
	case 556..560: return "556-560";
	case 561..565: return "561-565";
	case 566..570: return "566-570";
	case 571..575: return "571-575";
	case 576..580: return "576-580";
	case 581..585: return "581-585";
	case 586..590: return "586-590";
	case 591..595: return "591-595";
	case 596..600: return "596-600";

	case 601..605: return "601-605";
	case 606..610: return "606-610";
	case 611..615: return "611-615";
	case 616..620: return "616-620";
	case 621..625: return "621-625";
	case 626..630: return "626-630";
	case 631..635: return "631-635";
	case 636..640: return "636-640";
	case 641..645: return "641-645";
	case 646..650: return "646-650";
	case 651..655: return "651-655";
	case 656..660: return "656-660";
	case 661..665: return "661-665";
	case 666..670: return "666-670";
	case 671..675: return "671-675";
	case 676..680: return "676-680";
	case 681..685: return "681-685";
	case 686..690: return "686-690";
	case 691..695: return "691-695";
	case 696..700: return "696-700";

	case 701..705: return "701-705";
	case 706..710: return "706-710";
	case 711..715: return "711-715";
	case 716..720: return "716-720";
	case 721..725: return "721-725";
	case 726..730: return "726-730";
	case 731..735: return "731-735";
	case 736..740: return "736-740";
	case 741..745: return "741-745";
	case 746..750: return "746-750";
	case 751..755: return "751-755";
	case 756..760: return "756-760";
	case 761..765: return "761-765";
	case 766..770: return "766-770";
	case 771..775: return "771-775";
	case 776..780: return "776-780";
	case 781..785: return "781-785";
	case 786..790: return "786-790";
	case 791..795: return "791-795";
	case 796..800: return "796-800";
	
	case 801..805: return "801-805";
	case 806..810: return "806-810";
	case 811..815: return "811-815";
	case 816..820: return "816-820";
	case 821..825: return "821-825";
	case 826..830: return "826-830";
	case 831..835: return "831-835";
	case 836..840: return "836-840";
	case 841..845: return "841-845";
	case 846..850: return "846-850";
	case 851..855: return "851-855";
	case 856..860: return "856-860";
	case 861..865: return "861-865";
	case 866..870: return "866-870";
	case 871..875: return "871-875";
	case 876..880: return "876-880";
	case 881..885: return "881-885";
	case 886..890: return "886-890";
	case 891..895: return "891-895";
	case 896..900: return "896-900";
	
	case 901..905: return "901-905";
	case 906..910: return "906-910";
	case 911..915: return "911-915";
	case 916..920: return "916-920";
	case 921..925: return "921-925";
	case 926..930: return "926-930";
	case 931..935: return "931-935";
	case 936..940: return "936-940";
	case 941..945: return "941-945";
	case 946..950: return "946-950";
	case 951..955: return "951-955";
	case 956..960: return "956-960";
	case 961..965: return "961-965";
	case 966..970: return "966-970";
	case 971..975: return "971-975";
	case 976..980: return "976-980";
	case 981..985: return "981-985";
	case 986..990: return "986-990";
	case 991..995: return "991-995";
	case 996..1000: return "996-1000";

	case 1001..1100: return "1001-1100";
    case 1101..1200: return "1101-1200";
    case 1201..1300: return "1201-1300";
    case 1301..1400: return "1301-1400";
    case 1401..1500: return "1401-1500";
    case 1501..1600: return "1501-1600";
    case 1601..1700: return "1601-1700";
    case 1701..1800: return "1701-1800";
    case 1801..1900: return "1801-1900";
    case 1901..2000: return "1101-2000";

	case 2001..2100: return "2001-2100";
    case 2101..2200: return "2101-2200";
    case 2201..2300: return "2201-2300";
    case 2301..2400: return "2301-2400";
    case 2401..2500: return "2401-2500";
    case 2501..2600: return "2501-2600";
    case 2601..2700: return "2601-2700";
    case 2701..2800: return "2701-2800";
    case 2801..2900: return "2801-2900";
    case 2901..3000: return "2101-3000";

	case 3001..3100: return "3001-3100";
    case 3101..3200: return "3101-3200";
    case 3201..3300: return "3201-3300";
    case 3301..3400: return "3301-3400";
    case 3401..3500: return "3401-3500";
    case 3501..3600: return "3501-3600";
    case 3601..3700: return "3601-3700";
    case 3701..3800: return "3701-3800";
    case 3801..3900: return "3801-3900";
    case 3901..4000: return "3101-4000";

	case 4001..4100: return "4001-4100";
    case 4101..4200: return "4101-4200";
    case 4201..4300: return "4201-4300";
    case 4301..4400: return "4301-4400";
    case 4401..4500: return "4401-4500";
    case 4501..4600: return "4501-4600";
    case 4601..4700: return "4601-4700";
    case 4701..4800: return "4701-4800";
    case 4801..4900: return "4801-4900";
    case 4901..5000: return "4901-5000";
	
    case 5001..6000: return "5001-6000";
    case 6001..7000: return "6001-7000";
    case 7001..8000: return "7001-8000";
    case 8001..9000: return "8001-9000";
    case 9001..10000: return "9001-10000";
    case 10001..11000: return "10001-11000";
    case 11001..12000: return "11001-12000";
    case 12001..13000: return "12001-13000";
    case 13001..14000: return "13001-14000";
    case 14001..15000: return "14001-15000";
    case 15001..16000: return "15001-16000";
    case 16001..17000: return "16001-17000";
    case 17001..18000: return "17001-18000";
    case 18001..19000: return "18001-19000";
    case 19001..20000: return "19001-20000";

    case 20001..21000: return "20001-21000";
    case 21001..22000: return "21001-22000";
    case 22001..23000: return "22001-23000";
    case 23001..24000: return "23001-24000";
    case 24001..25000: return "24001-25000";
    case 25001..26000: return "25001-26000";
    case 26001..27000: return "26001-27000";
    case 27001..28000: return "27001-28000";
    case 28001..29000: return "28001-29000";
    case 29001..30000: return "29001-30000";

    case 30001..31000: return "30001-31000";
    case 31001..32000: return "31001-32000";
    case 32001..33000: return "32001-33000";
    case 33001..34000: return "33001-34000";
    case 34001..35000: return "34001-35000";
    case 35001..36000: return "35001-36000";
    case 36001..37000: return "36001-37000";
    case 37001..38000: return "37001-38000";
    case 38001..39000: return "38001-39000";
    case 39001..40000: return "39001-40000";

    case 40001..41000: return "40001-41000";
    case 41001..42000: return "41001-42000";
    case 42001..43000: return "42001-43000";
    case 43001..44000: return "43001-44000";
    case 44001..45000: return "44001-45000";
    case 45001..46000: return "45001-46000";
    case 46001..47000: return "46001-47000";
    case 47001..48000: return "47001-48000";
    case 48001..49000: return "48001-49000";
    case 49001..50000: return "49001-50000";

    case 50001..1000000: return "big number";
  default:
    return "unknown";
  }
}


void skill_func(object from, object at, string arg) {
  object *ob;
  string tmp, *types1, *types2, what1, what2;
  float *avg;
  int *wc;
  int *vals, count, which, i;

  if(sscanf(arg, "%s and %s", what1, what2) != 2) {
    message("info", "Format: use compare at <what> and <what>",from);
    remove();
    return;
  }
  ob = allocate(2);
  ob[0] = present(what1, from);
  ob[1] = present(what2, from);
  if(!ob[0]) {
    message("info", "You do not have a "+what1+".", from);
    remove();
    return;
  }
  if(!ob[1]) {
    message("info", "You do not have a "+what2+".", from);
    remove();
    return;
  }
  count = (member_array("std/weapon.c", deep_inherit_list(ob[0])) >= 0 &&
	   member_array("std/weapon.c", deep_inherit_list(ob[1])) >= 0);
  count = count || (member_array("std/armour.c", deep_inherit_list(ob[0])) >= 0 &&
		    member_array("std/armour.c", deep_inherit_list(ob[1])) >= 0);
  if(!count) {
    message("info", "The items you compare must either be both weapons or "+
	    "both armours.", from);
    remove();
    return;
  }
  if(ob[0]->is_weapon()) {
    switch(props["skill level"]) {
    case 61..10000:
      types1 = keys(ob[0]->query_all_wc());
      types2 = keys(ob[1]->query_all_wc());
      tmp = sprintf("%-31s %-31s", (string)ob[0]->query_short(),
		    (string)ob[1]->query_short()) + "\n";
      for(i = 0; (i < sizeof(types1) && i < sizeof(types2)); i++) {
	if(i < sizeof(types1))
	  what1 = sprintf("%-15s %-10s      ",types1[i]+":",
			wc_str((int)ob[0]->query_wc(types1[i])));
	  //what1 = sprintf("%-15s %-10s      ",types1[i]+":",
			  //wc_str((int)ob[0]->query_wc(types1[i])));
	else what1 = sprintf("%' '31s ", "");
	if(i < sizeof(types2))
	  what2 = sprintf("%-20s %-10s",types2[i]+":",
                          wc_str((int)ob[1]->query_wc(types2[i])));
        else what2 = sprintf("%' '31s", "");
	tmp += what1 + what2 + "\n";
      }
      message("my_action", tmp+"\n", from);
    case -10..60:
      wc = allocate(2);
      for(i=0; i<=1; i++) {
      	vals = values(ob[i]->query_all_wc());
	count = sizeof(vals);
	while(count--) wc[i] += vals[count];
      }
      if(abs(wc[0] - wc[1]) < ((100 - props["skill level"])) / 5) {
	message("my_action", "The two appear to be roughly equal.", from);
	remove();
	return;
      }
      if(wc[0] > wc[1]) i = 0;
      else i = 1;
      message("my_action", (string)ob[i]->query_short() + " seems to be "+
	      "the better weapon.", from);
      remove();
      return;
    }
    remove();
    return;
  } else {
    switch(props["skill level"]) {
    case 61..10000:
      types1 = keys(ob[0]->query_all_ac());
      types2 = keys(ob[1]->query_all_ac());
      tmp = sprintf("%-31s %-31s", (string)ob[0]->query_short(),
                    (string)ob[1]->query_short()) + "\n";
      for(i = 0; (i < sizeof(types1) && i < sizeof(types2)); i++) {
        if(i < sizeof(types1))
          what1 = sprintf("%-15s %-10s      ",types1[i]+":",
                          wc_str((int)ob[0]->query_ac(types1[i])));
          //what1 = sprintf("%-15s %-10s      ",types1[i]+":",
                          //wc_str((int)ob[0]->query_ac(types1[i])));
        else what1 = sprintf("%' '31s ", "");
        if(i < sizeof(types2))
          what2 = sprintf("%-15s %-10s     ",types2[i]+":",
                          wc_str((int)ob[1]->query_ac(types2[i])));
        else what2 = sprintf("%' '31s", "");
        tmp += what1 + what2 + "\n";
      }
      message("my_action", tmp+"\n", from);
    case -100..60:
      avg = allocate(2);
      avg[0] = 0.0;  avg[1] = 0.0;
      for(i=0; i <= 1; i++) {
	vals = values(ob[i]->query_all_ac());
	for(count = 0; count < sizeof(vals); count++)
	  avg[i] += vals[count];
	avg[i] /= (count + 1);
      }
      if(abs(to_int(avg[0] - avg[1])) < ((100 - props["skill level"]) / 7)) {
        message("my_action", "The two appear to be roughly equal.", from);
        remove();
        return;
      }
      if(avg[0] > avg[1]) i = 0;
      else i = 1;
      message("my_action", (string)ob[i]->query_short() + " seems to be "+
              "the better armour.", from);
    default:
      remove();
      return;
    }
    remove();
    return;
  }
  remove();
  return;
}

int abs(int num) {
  if(num >= 0) return num;
  else return -1 * num;
}
