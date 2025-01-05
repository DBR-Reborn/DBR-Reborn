#include <std.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("soul orb");
    set_id(({ "orb", "soul orb", "nethermancer orb", "nethermancer soul orb" }));
    set_short("A soul orb");
    set_long("This is a perfectly spherical glass orb approximately nine inches in diameter. Another very small sphere is suspended in the exact center of its interior that seems to give off a faint glow appearing to draw energy inward towards it without rest. It is with this orb that a Nethermancer performs all of his or her duties with the various souls of the dead, ranging from simple infusion to combining others together and even bringing them to life.\n");
    set_weight(50);
    set_value(100);
 call_out("soulcount", 2);
    return;
}

void soulcount() {
    mixed desc;
    this_object()->remove_property("extra long");

    /*
	set_long("This is a perfectly spherical glass orb approximately nine inches in diameter. Another very small sphere is suspended in the exact center of its interior that seems to give off a faint glow appearing to draw energy inward towards it without rest. It is with this orb that a Nethermancer performs all of his or her duties with the various souls of the dead, ranging from simple infusion to combining others together and even bringing them to life.\n");
    */

    if(this_object()->query_property("total souls") < 1) {
	desc = this_object()->query_property("extra long");
	if(!desc) desc = ({});
	desc += ({ "This orb currently contains no souls." });
	set_property("extra long", desc);
    }
    if(this_object()->query_property("soul orb finalize") > 0) {
	set_short("A soul orb (%^CYAN%^finalized%^RESET%^)");
	desc = this_object()->query_property("extra long");
	if(!desc) desc = ({});
	desc += ({ "%^YELLOW%^This orb is finalized and prepared for sacrifice or undead raising.%^RESET%^" });
	set_property("extra long", desc);
    }
    if(this_object()->query_property("fumbled") > 0) {
	set_short("A soul orb (%^RED%^destabilized%^RESET%^)");
	desc = this_object()->query_property("extra long");
	if(!desc) desc = ({});
	desc += ({ "%^RED%^This orb is destabilized and cannot recieve any more souls.%^RESET%^" });
	set_property("extra long", desc);
    }
    if(this_object()->query_property("bone man souls") > 0) {
	desc = this_object()->query_property("extra long");
	if(!desc) desc = ({});
	if(this_object()->query_property("bone man souls") < 2) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("bone man souls")+"%^RESET%^ bone man soul." });
	}
	if(this_object()->query_property("bone man souls") > 1) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("bone man souls")+"%^RESET%^ bone man souls." });
	}
	set_property("extra long", desc);
    }
    if(this_object()->query_property("rotted zombie souls") > 0) {
	desc = this_object()->query_property("extra long");
	if(!desc) desc = ({});
	if(this_object()->query_property("rotted zombie souls") < 2) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("rotted zombie souls")+"%^RESET%^ rotted zombie soul." });
	}
	if(this_object()->query_property("rotted zombie souls") > 1) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("rotted zombie souls")+"%^RESET%^ rotted zombie souls." });
	}
	set_property("extra long", desc);
    }
    if(this_object()->query_property("skeletal zombie souls") > 0) {
	desc = this_object()->query_property("extra long");
	if(!desc) desc = ({});
	if(this_object()->query_property("skeletal zombie souls") < 2) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("skeletal zombie souls")+"%^RESET%^ skeletal zombie soul." });
	}
	if(this_object()->query_property("skeletal zombie souls") > 1) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("skeletal zombie souls")+"%^RESET%^ skeletal zombie souls." });
	}
	set_property("extra long", desc);
    }
    if(this_object()->query_property("revenant souls") > 0) {
	desc = this_object()->query_property("extra long");
	if(!desc) desc = ({});
	if(this_object()->query_property("revenant souls") < 2) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("revenant souls")+"%^RESET%^ revenant soul." });
	}
	if(this_object()->query_property("revenant souls") > 1) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("revenant souls")+"%^RESET%^ revenant souls." });
	}
	set_property("extra long", desc);
    }
    if(this_object()->query_property("blood hound souls") > 0) {
	desc = this_object()->query_property("extra long");
	if(!desc) desc = ({});
	if(this_object()->query_property("blood hound souls") < 2) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("blood hound souls")+"%^RESET%^ blood hound soul." });
	}
	if(this_object()->query_property("blood hound souls") > 1) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("blood hound souls")+"%^RESET%^ blood hound souls." });
	}
	set_property("extra long", desc);
    }
    if(this_object()->query_property("bone hound souls") > 0) {
	desc = this_object()->query_property("extra long");
	if(!desc) desc = ({});
	if(this_object()->query_property("bone hound souls") < 2) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("bone hound souls")+"%^RESET%^ bone hound soul." });
	}
	if(this_object()->query_property("bone hound souls") > 1) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("bone hound souls")+"%^RESET%^ bone hound souls." });
	}
	set_property("extra long", desc);
    }
    if(this_object()->query_property("undead beast souls") > 0) {
	desc = this_object()->query_property("extra long");
	if(!desc) desc = ({});
	if(this_object()->query_property("undead beast souls") < 2) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("undead beast souls")+"%^RESET%^ undead beast soul." });
	}
	if(this_object()->query_property("undead beast souls") > 1) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("undead beast souls")+"%^RESET%^ undead beast souls." });
	}
	set_property("extra long", desc);
    }
    if(this_object()->query_property("ghost souls") > 0) {
	desc = this_object()->query_property("extra long");
	if(!desc) desc = ({});
	if(this_object()->query_property("ghost souls") < 2) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("ghost souls")+"%^RESET%^ ghost soul." });
	}
	if(this_object()->query_property("ghost souls") > 1) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("ghost souls")+"%^RESET%^ ghost souls." });
	}
	set_property("extra long", desc);
    }
    if(this_object()->query_property("ghast dog souls") > 0) {
	desc = this_object()->query_property("extra long");
	if(!desc) desc = ({});
	if(this_object()->query_property("ghast dog souls") < 2) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("ghast dog souls")+"%^RESET%^ ghast dog soul." });
	}
	if(this_object()->query_property("ghast dog souls") > 1) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("ghast dog souls")+"%^RESET%^ ghast dog souls." });
	}
	set_property("extra long", desc);
    }
    if(this_object()->query_property("zombie spirit souls") > 0) {
	desc = this_object()->query_property("extra long");
	if(!desc) desc = ({});
	if(this_object()->query_property("zombie spirit souls") < 2) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("zombie spirit souls")+"%^RESET%^ zombie spirit soul." });
	}
	if(this_object()->query_property("zombie spirit souls") > 1) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("zombie spirit souls")+"%^RESET%^ zombie spirit souls." });
	}
	set_property("extra long", desc);
    }
    if(this_object()->query_property("skeletal essence souls") > 0) {
	desc = this_object()->query_property("extra long");
	if(!desc) desc = ({});
	if(this_object()->query_property("skeletal essence souls") < 2) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("skeletal essence souls")+"%^RESET%^ skeletal essence soul." });
	}
	if(this_object()->query_property("skeletal essence souls") > 1) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("skeletal essence souls")+"%^RESET%^ skeletal essence souls." });
	}
	set_property("extra long", desc);
    }
    if(this_object()->query_property("blood fiend souls") > 0) {
	desc = this_object()->query_property("extra long");
	if(!desc) desc = ({});
	if(this_object()->query_property("blood fiend souls") < 2) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("blood fiend souls")+"%^RESET%^ blood fiend soul." });
	}
	if(this_object()->query_property("blood fiend souls") > 1) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("blood fiend souls")+"%^RESET%^ blood fiend souls." });
	}
	set_property("extra long", desc);
    }
    if(this_object()->query_property("vampiric hound souls") > 0) {
	desc = this_object()->query_property("extra long");
	if(!desc) desc = ({});
	if(this_object()->query_property("vampiric hound souls") < 2) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("vampiric hound souls")+"%^RESET%^ vampiric hound soul." });
	}
	if(this_object()->query_property("vampiric hound souls") > 1) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("vampiric hound souls")+"%^RESET%^ vampiric hound souls." });
	}
	set_property("extra long", desc);
    }
    if(this_object()->query_property("fanged spirit souls") > 0) {
	desc = this_object()->query_property("extra long");
	if(!desc) desc = ({});
	if(this_object()->query_property("fanged spirit souls") < 2) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("fanged spirit souls")+"%^RESET%^ fanged spirit soul." });
	}
	if(this_object()->query_property("fanged spirit souls") > 1) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("fanged spirit souls")+"%^RESET%^ fanged spirit souls." });
	}
	set_property("extra long", desc);
    }
    if(this_object()->query_property("black essence souls") > 0) {
	desc = this_object()->query_property("extra long");
	if(!desc) desc = ({});
	if(this_object()->query_property("black essence souls") < 2) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("black essence souls")+"%^RESET%^ black essence soul." });
	}
	if(this_object()->query_property("black essence souls") > 1) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("black essence souls")+"%^RESET%^ black essence souls." });
	}
	set_property("extra long", desc);
    }
    if(this_object()->query_property("red ghoul souls") > 0) {
	desc = this_object()->query_property("extra long");
	if(!desc) desc = ({});
	if(this_object()->query_property("red ghoul souls") < 2) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("red ghoul souls")+"%^RESET%^ red ghoul soul." });
	}
	if(this_object()->query_property("red ghoul souls") > 1) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("red ghoul souls")+"%^RESET%^ red ghoul souls." });
	}
	set_property("extra long", desc);
    }
    if(this_object()->query_property("dark knight souls") > 0) {
	desc = this_object()->query_property("extra long");
	if(!desc) desc = ({});
	if(this_object()->query_property("dark knight souls") < 2) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("dark knight souls")+"%^RESET%^ dark knight soul." });
	}
	if(this_object()->query_property("dark knight souls") > 1) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("dark knight souls")+"%^RESET%^ dark knight souls." });
	}
	set_property("extra long", desc);
    }
    if(this_object()->query_property("blood knight souls") > 0) {
	desc = this_object()->query_property("extra long");
	if(!desc) desc = ({});
	if(this_object()->query_property("blood knight souls") < 2) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("blood knight souls")+"%^RESET%^ blood knight soul." });
	}
	if(this_object()->query_property("blood knight souls") > 1) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("blood knight souls")+"%^RESET%^ blood knight souls." });
	}
	set_property("extra long", desc);
    }
    if(this_object()->query_property("essence warrior souls") > 0) {
	desc = this_object()->query_property("extra long");
	if(!desc) desc = ({});
	if(this_object()->query_property("essence warrior souls") < 2) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("essence warrior souls")+"%^RESET%^ essence warrior soul." });
	}
	if(this_object()->query_property("essence warrior souls") > 1) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("essence warrior souls")+"%^RESET%^ essence warrior souls." });
	}
	set_property("extra long", desc);
    }
    if(this_object()->query_property("chaos shadow souls") > 0) {
	desc = this_object()->query_property("extra long");
	if(!desc) desc = ({});
	if(this_object()->query_property("chaos shadow souls") < 2) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("chaos shadow souls")+"%^RESET%^ chaos shadow soul." });
	}
	if(this_object()->query_property("chaos shadow souls") > 1) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("chaos shadow souls")+"%^RESET%^ chaos shadow souls." });
	}
	set_property("extra long", desc);
    }
    if(this_object()->query_property("soul knight souls") > 0) {
	desc = this_object()->query_property("extra long");
	if(!desc) desc = ({});
	if(this_object()->query_property("soul knight souls") < 2) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("soul knight souls")+"%^RESET%^ soul knight soul." });
	}
	if(this_object()->query_property("soul knight souls") > 1) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("soul knight souls")+"%^RESET%^ soul knight souls." });
	}
	set_property("extra long", desc);
    }
    if(this_object()->query_property("shadow beast souls") > 0) {
	desc = this_object()->query_property("extra long");
	if(!desc) desc = ({});
	if(this_object()->query_property("shadow beast souls") < 2) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("shadow beast souls")+"%^RESET%^ shadow beast soul." });
	}
	if(this_object()->query_property("shadow beast souls") > 1) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("shadow beast souls")+"%^RESET%^ shadow beast souls." });
	}
	set_property("extra long", desc);
    }
    if(this_object()->query_property("deathmage souls") > 0) {
	desc = this_object()->query_property("extra long");
	if(!desc) desc = ({});
	if(this_object()->query_property("deathmage souls") < 2) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("deathmage souls")+"%^RESET%^ deathmage soul." });
	}
	if(this_object()->query_property("deathmage souls") > 1) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("deathmage souls")+"%^RESET%^ deathmage souls." });
	}
	set_property("extra long", desc);
    }
    if(this_object()->query_property("gravewyrm souls") > 0) {
	desc = this_object()->query_property("extra long");
	if(!desc) desc = ({});
	if(this_object()->query_property("gravewyrm souls") < 2) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("gravewyrm souls")+"%^RESET%^ gravewyrm soul." });
	}
	if(this_object()->query_property("gravewyrm souls") > 1) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("gravewyrm souls")+"%^RESET%^ gravewyrm souls." });
	}
	set_property("extra long", desc);
    }
    if(this_object()->query_property("shadowflame templar souls") > 0) {
	desc = this_object()->query_property("extra long");
	if(!desc) desc = ({});
	if(this_object()->query_property("shadowflame templar souls") < 2) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("shadowflame templar souls")+"%^RESET%^ shadowflame templar soul." });
	}
	if(this_object()->query_property("shadowflame templar souls") > 1) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("shadowflame templar souls")+"%^RESET%^ shadowflame templar souls." });
	}
	set_property("extra long", desc);
    }
    if(this_object()->query_property("death dragon souls") > 0) {
	desc = this_object()->query_property("extra long");
	if(!desc) desc = ({});
	if(this_object()->query_property("death dragon souls") < 2) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("death dragon souls")+"%^RESET%^ death dragon soul." });
	}
	if(this_object()->query_property("death dragon souls") > 1) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("death dragon souls")+"%^RESET%^ death dragon souls." });
	}
	set_property("extra long", desc);
    }
    if(this_object()->query_property("nether lord souls") > 0) {
	desc = this_object()->query_property("extra long");
	if(!desc) desc = ({});
	if(this_object()->query_property("nether lord souls") < 2) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("nether lord souls")+"%^RESET%^ nether lord soul." });
	}
	if(this_object()->query_property("nether lord souls") > 1) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("nether lord souls")+"%^RESET%^ nether lord souls." });
	}
	set_property("extra long", desc);
    }
    if(this_object()->query_property("eternal darkness souls") > 0) {
	desc = this_object()->query_property("extra long");
	if(!desc) desc = ({});
	if(this_object()->query_property("eternal darkness souls") < 2) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("eternal darkness souls")+"%^RESET%^ eternal darkness soul." });
	}
	if(this_object()->query_property("eternal darkness souls") > 1) {
	    desc += ({ "This orb contains %^MAGENTA%^"+(int)this_object()->query_property("eternal darkness souls")+"%^RESET%^ eternal darkness souls." });
	}
	set_property("extra long", desc);
    }
    call_out("soulcount", 2);
}
