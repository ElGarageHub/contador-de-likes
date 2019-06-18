thickness =  3;
dent_size = 10;

module hdent() {
  square([dent_size, thickness]);
}

module vdent() {
  square([thickness, dent_size]);
}

module face() {
  difference() {
    square([300, 60]);
    for(i=[0 : dent_size*2 : 300 - dent_size]) translate([i, 0]) hdent();
    for(i=[0 : dent_size*2 : 300 - dent_size]) translate([i, 60-thickness]) hdent();
    for(i=[5 : dent_size*2 : 60 - dent_size]) translate([0, i]) vdent();
    for(i=[5 : dent_size*2 : 60 - dent_size]) translate([300-thickness, i]) vdent();
  }
}

module side() {
  difference() {
    square([60, 60]);
    for(i=[5 - dent_size : dent_size*2 : 60]) translate([i, 0]) hdent();
    for(i=[5 - dent_size : dent_size*2 : 60]) translate([i, 60-thickness]) hdent();
    for(i=[5 - dent_size : dent_size*2 : 60]) translate([0, i]) vdent();
    for(i=[5 - dent_size: dent_size*2 : 60]) translate([60-thickness, i]) vdent();
  }
}

module front_face() {
  difference() {
    face();
    translate([49, 9]) square([242, 42]);
  }
}

front_face();
for(i=[1 : 1 : 3]) translate([0, 65*i]) face();
for(i=[0 : 1 : 1]) translate([305, 65*i]) side();