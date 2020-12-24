#ifndef DHFTREE_H
#define DHFTREE_H

/*
   NAMING CONVENTIONS

   rec_i   : input variables for reconstructed particles (data)
   rec_m   : output variables for reconstructed particles (data) with combinations
*/

struct rec_i {
  // electron
  Float_t Q2;
  Float_t W;
  Float_t Nu;
  Float_t Xb;
  Float_t Yb;
  Float_t vxe;
  Float_t vye;
  Float_t vze;
  Float_t SectorEl;
  Float_t TargType;
  Float_t Pex;
  Float_t Pey;
  Float_t Pez;
  Float_t BettaEl;
  Float_t vxec;
  Float_t vyec;
  Float_t vzec;
  Float_t ThetaLabEl;
  Float_t PhiLabEl;
  // particle
  Float_t Eh;
  Float_t Zh;
  Float_t ThetaPQ;
  Float_t Pt2;
  Float_t Pl2;
  Float_t PhiPQ;
  Float_t Mx2;
  Float_t ThetaLab;
  Float_t PhiLab;
  Float_t vxh;
  Float_t vyh;
  Float_t vzh;
  Float_t Sector;
  Float_t Px;
  Float_t Py;
  Float_t Pz;
  Float_t Betta;
  Float_t Mass2;
  Float_t pid;
  Float_t T4;
  Float_t deltaZ;
  // event (1)
  Float_t evnt;
};

struct rec_m {
  // electron
  Float_t Q2;
  Float_t W;
  Float_t Nu;
  Float_t Xb;
  Float_t Yb;
  Float_t vxe;
  Float_t vye;
  Float_t vze;
  Float_t SectorEl;
  Float_t TargType;
  Float_t Pex;
  Float_t Pey;
  Float_t Pez;
  Float_t BettaEl;
  Float_t vxec;
  Float_t vyec;
  Float_t vzec;
  Float_t ThetaLabEl;
  Float_t PhiLabEl;
  // particles
  Float_t vxh;
  Float_t vyh;
  Float_t vzh;
  Float_t Sector;
  Float_t Betta;
  Float_t Mass2;
  Float_t Pid;
  Float_t T4;
  Float_t Eh;
  Float_t Px;
  Float_t Py;
  Float_t Pz;
  Float_t Zh;
  Float_t Pt2;
  Float_t Pl2;
  Float_t Mx2;
  Float_t ThetaPQ;
  Float_t PhiPQ;
  Float_t ThetaLab;
  Float_t PhiLab;
  Float_t deltaZ;
  Float_t deltaTheta;
  // number of particles (2)
  Float_t nPip;
  Float_t nPim;
  // event related (2)
  Float_t Entry;
  Float_t Event;
};

#endif
