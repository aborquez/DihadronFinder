/*****************************************/
/*  DihadronFinder_data.cxx              */
/*                                       */
/*  Andrés Bórquez                       */
/*                                       */
/*****************************************/

// December 2020

#include "DihadronFinder_data.hxx"

int main(int argc, char **argv) {

  gDataKind = "data";

  parseCommandLine(argc, argv);
  assignOptions();
  printOptions();

  /*** DECLARATIONS ***/

  // data counting variables
  std::vector<int> pipVector;
  std::vector<int> pimVector;
  Bool_t dihadronCondition = false;

  /*** DATA STRUCTURES ***/

  // input
  rec_i t;

  // output
  rec_m m;

  /*** INPUT ***/

  TChain *tree = new TChain();
  tree->Add(gInputFile + "/ntuple_data");  // input

  /*** OUTPUT ***/

  TFile *rootFile = new TFile(gOutputFile, "RECREATE", "Omega Meson Filtered Combinations");

  TTree *tMix = new TTree("mix", "Combination of particles");
  SetMixBranches_REC(tMix, m);

  /*** START ***/

  // turn on all input leaves
  tree->SetBranchStatus("*", 1);
  SetInputBranches_REC(tree, t);

  Int_t Ne = (Int_t)tree->GetEntries();
#ifdef DEBUG
  Ne = 1000;
#else
#endif

  Int_t currentEvent, previousEvent;

  // loop in entries
  for (Int_t i = 0; i <= Ne; i++) {
    tree->GetEntry(i);
    currentEvent = (Int_t)t.evnt;

    // prevents repetition of same event
    if (i > 0) {
      tree->GetEntry(i - 1);
      previousEvent = (Int_t)t.evnt;
      if (previousEvent == currentEvent) continue;
    }

#ifdef DEBUG
    std::cout << "Current event number: " << currentEvent << std::endl;
    std::cout << "Current entry number: " << i << std::endl;
    std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
#else
#endif

    // count particles in the current event
    for (Int_t j = i; j <= Ne; j++) {
      tree->GetEntry(j);
      if (currentEvent == (Int_t)t.evnt) {

#ifdef DEBUG
        std::cout << "  Entry number: " << j << std::endl;
        std::cout << "  pid    =      " << t.pid << std::endl;
        std::cout << "  Zh     =      " << t.Zh << std::endl;
        std::cout << "  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl;
#else
#endif
        // count the particles
        if (t.pid == (Float_t)211) {
          pipVector.push_back(j);
	  if (t.Zh > 0.5) dihadronCondition = true;
	} else if (t.pid == (Float_t)-211) {
          pimVector.push_back(j);
	  if (t.Zh > 0.5) dihadronCondition = true;
	}
        
      } else {
        break;
      }
    }

    // commentary
#ifdef DEBUG
    std::cout << "  nPip     = " << pipVector.size() << std::endl;
    std::cout << "  nPim     = " << pimVector.size() << std::endl;
    std::cout << "  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl;
#else
#endif

    /*** FILL ***/

    // check dihadron condition
    if (dihadronCondition) {

#ifdef DEBUG
      std::cout << "  % DIHADRON FOUND!!!                   %" << std::endl;
      std::cout << "  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl;
#else
#endif

      // loop on positive pions
      for (Size_t pp = 0; pp < pipVector.size(); pp++) {
        tree->GetEntry(pipVector[pp]);
        AssignMixVar_REC(t, m, pipVector[pp]);
	// assign number of particles
        m.nPip = (Int_t)pipVector.size();
	m.nPim = (Int_t)pimVector.size();
	tMix->Fill();
      }

      // loop on negative pions
      for (Size_t np = 0; np < pimVector.size(); np++) {
        tree->GetEntry(pimVector[np]);
        AssignMixVar_REC(t, m, pimVector[np]);
	// assign number of particles
	m.nPip = (Int_t)pipVector.size();
        m.nPim = (Int_t)pimVector.size();
        tMix->Fill();
      }
    }

    /*** RESET ***/

    pipVector.clear();
    pimVector.clear();
    dihadronCondition = false;

#ifdef DEBUG
    std::cout << "  !! Finished event" << std::endl;
    std::cout << std::endl;
#else
#endif
  }  // end of loop in entries

  /*** WRITE ***/

  rootFile->Write();
  rootFile->Close();

  std::cout << "This file has been created: " << gOutputFile << std::endl;

  return 0;
}
