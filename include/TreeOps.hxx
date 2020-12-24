#ifndef TREEOPS_HXX
#define TREEOPS_HXX

#include "Headers.hxx"
#include "Math.hxx"
#include "PDG.hxx"

#include "DHFtree.h"

#ifndef INVLD
#define INVLD -9999
#endif

void SetInputBranches_REC(TChain* chain, rec_i& t) {
  // electron (19)
  chain->SetBranchAddress("Q2", &t.Q2);
  chain->SetBranchAddress("W", &t.W);
  chain->SetBranchAddress("Nu", &t.Nu);
  chain->SetBranchAddress("Xb", &t.Xb);
  chain->SetBranchAddress("Yb", &t.Yb);
  chain->SetBranchAddress("vxe", &t.vxe);
  chain->SetBranchAddress("vye", &t.vye);
  chain->SetBranchAddress("vze", &t.vze);
  chain->SetBranchAddress("SectorEl", &t.SectorEl);
  chain->SetBranchAddress("TargType", &t.TargType);
  chain->SetBranchAddress("Pex", &t.Pex);
  chain->SetBranchAddress("Pey", &t.Pey);
  chain->SetBranchAddress("Pez", &t.Pez);
  chain->SetBranchAddress("BettaEl", &t.BettaEl);
  chain->SetBranchAddress("vxec", &t.vxec);
  chain->SetBranchAddress("vyec", &t.vyec);
  chain->SetBranchAddress("vzec", &t.vzec);
  chain->SetBranchAddress("ThetaLabEl", &t.ThetaLabEl);
  chain->SetBranchAddress("PhiLabEl", &t.PhiLabEl);
  // particles (21)
  chain->SetBranchAddress("Eh", &t.Eh);
  chain->SetBranchAddress("Zh", &t.Zh);
  chain->SetBranchAddress("ThetaPQ", &t.ThetaPQ);
  chain->SetBranchAddress("Pt2", &t.Pt2);
  chain->SetBranchAddress("Pl2", &t.Pl2);
  chain->SetBranchAddress("PhiPQ", &t.PhiPQ);
  chain->SetBranchAddress("Mx2", &t.Mx2);
  chain->SetBranchAddress("ThetaLab", &t.ThetaLab);
  chain->SetBranchAddress("PhiLab", &t.PhiLab);
  chain->SetBranchAddress("vxh", &t.vxh);
  chain->SetBranchAddress("vyh", &t.vyh);
  chain->SetBranchAddress("vzh", &t.vzh);
  chain->SetBranchAddress("Sector", &t.Sector);
  chain->SetBranchAddress("Px", &t.Px);
  chain->SetBranchAddress("Py", &t.Py);
  chain->SetBranchAddress("Pz", &t.Pz);
  chain->SetBranchAddress("Betta", &t.Betta);
  chain->SetBranchAddress("Mass2", &t.Mass2);
  chain->SetBranchAddress("pid", &t.pid);
  chain->SetBranchAddress("T4", &t.T4);
  chain->SetBranchAddress("deltaZ", &t.deltaZ);
  // event (1)
  chain->SetBranchAddress("evnt", &t.evnt);
}

void SetMixBranches_REC(TTree* tree, rec_m& m) {
  // electron (19)
  tree->Branch("Q2", &m.Q2);
  tree->Branch("W", &m.W);
  tree->Branch("Nu", &m.Nu);
  tree->Branch("Xb", &m.Xb);
  tree->Branch("Yb", &m.Yb);
  tree->Branch("vxe", &m.vxe);
  tree->Branch("vye", &m.vye);
  tree->Branch("vze", &m.vze);
  tree->Branch("SectorEl", &m.SectorEl);
  tree->Branch("TargType", &m.TargType);
  tree->Branch("Pex", &m.Pex);
  tree->Branch("Pey", &m.Pey);
  tree->Branch("Pez", &m.Pez);
  tree->Branch("BettaEl", &m.BettaEl);
  tree->Branch("PhiLabEl", &m.PhiLabEl);
  tree->Branch("ThetaLabEl", &m.ThetaLabEl);
  tree->Branch("vxec", &m.vxec);
  tree->Branch("vyec", &m.vyec);
  tree->Branch("vzec", &m.vzec);
  // particles (23)
  tree->Branch("vxh", &m.vxh);
  tree->Branch("vyh", &m.vyh);
  tree->Branch("vzh", &m.vzh);
  tree->Branch("Sector", &m.Sector);
  tree->Branch("Betta", &m.Betta);
  tree->Branch("Mass2", &m.Mass2);
  tree->Branch("Pid", &m.Pid);
  tree->Branch("T4", &m.T4);
  tree->Branch("Px", &m.Px);
  tree->Branch("Py", &m.Py);
  tree->Branch("Pz", &m.Pz);
  tree->Branch("Eh", &m.Eh);
  tree->Branch("Zh", &m.Zh);
  tree->Branch("PhiPQ", &m.PhiPQ);
  tree->Branch("ThetaPQ", &m.ThetaPQ);
  tree->Branch("PhiLab", &m.PhiLab);
  tree->Branch("ThetaLab", &m.ThetaLab);
  tree->Branch("Pt2", &m.Pt2);
  tree->Branch("Pl2", &m.Pl2);
  tree->Branch("Mx2", &m.Mx2);
  tree->Branch("deltaTheta", &m.deltaTheta);
  tree->Branch("deltaZ", &m.deltaZ);
  // number of particles in that event (4)
  tree->Branch("nPip", &m.nPip);
  tree->Branch("nPim", &m.nPim);
  // event related (2)
  tree->Branch("Entry", &m.Entry);
  tree->Branch("Event", &m.Event);
}

void AssignMixVar_REC(rec_i& t, rec_m& m, Int_t entry) {
  // electron (19)
  m.Q2 = t.Q2;
  m.W = t.W;
  m.Nu = t.Nu;
  m.Xb = t.Xb;
  m.Yb = t.Yb;
  m.vxe = t.vxe;
  m.vye = t.vye;
  m.vze = t.vze;
  m.SectorEl = t.SectorEl;
  m.TargType = t.TargType;
  m.Pex = t.Pex;
  m.Pey = t.Pey;
  m.Pez = t.Pez;
  m.BettaEl = t.BettaEl;
  m.PhiLabEl = PhiLab(t.Pex, t.Pey, t.Pez);
  m.ThetaLabEl = ThetaLab(t.Pex, t.Pey, t.Pez);
  m.vxec = t.vxec;
  m.vyec = t.vyec;
  m.vzec = t.vzec;
  // particles (22)
  m.vxh = t.vxh;
  m.vyh = t.vyh;
  m.vzh = t.vzh;
  m.Sector = t.Sector;
  m.deltaZ = t.deltaZ;
  m.T4 = t.T4;
  m.Mass2 = t.Mass2;
  m.Betta = t.Betta;
  m.Pid = t.pid;  // important!
  m.Eh = t.Eh;
  m.Px = t.Px;
  m.Py = t.Py;
  m.Pz = t.Pz;
  m.Zh = m.Eh / m.Nu;
  Double_t fP = TMath::Sqrt(m.Px * m.Px + m.Py * m.Py + m.Pz * m.Pz);
  Double_t fCosThetaPQ = ((kEbeam - m.Pez) * m.Pz - m.Pex * m.Px - m.Pey * m.Py) / (TMath::Sqrt(fP * fP * (m.Q2 + m.Nu * m.Nu)));
  m.PhiPQ = PhiPQ(t.Pex, t.Pey, t.Pez, m.Px, m.Py, m.Pz);
  m.ThetaPQ = ThetaPQ(t.Pex, t.Pey, t.Pez, m.Px, m.Py, m.Pz);
  m.PhiLab = PhiLab(m.Px, m.Py, m.Pz);
  m.ThetaLab = ThetaLab(m.Px, m.Py, m.Pz);
  m.Pt2 = fP * fP * (1 - fCosThetaPQ * fCosThetaPQ);
  m.Pl2 = fP * fP * fCosThetaPQ * fCosThetaPQ;
  m.deltaTheta = DeltaTheta(t.Pex, t.Pey, t.Pez, m.Px, m.Py, m.Pz);
  Double_t fM = GetParticleMass((Int_t)t.pid);
  m.Mx2 = m.W * m.W + fM * fM - 2 * m.Zh * m.Nu * m.Nu + 2 * TMath::Sqrt(m.Pl2 * (m.Nu * m.Nu + m.Q2)) - 2 * kMassProton * m.Zh * m.Nu;
  // event-related (2)
  m.Entry = (Float_t)entry;
  m.Event = t.evnt;
}

#endif
