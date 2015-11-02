#include "TFile.h"
#include "TTree.h"
#include <iostream>

void run()
{
	// input file for emulated bits
	TFile* inEm = TFile::Open("openHLT_1000.root");

	//input file for data bits
	TFile* inDa = TFile::Open("histo_MBBits_10000.root");

	TTree* inTreeEm = (TTree*)inEm->Get("hltbitanalysis/HltTree");
	TTree* inTreeDa = (TTree*)inDa->Get("demo/MBBits");

	int HF1ORem;
	int HF2ORem;
	int HF1ANDem;
	int HF2ANDem;
	ULong64_t event;
	int lumi;
	int run;	

	int HF1ORda;
        int HF2ORda;
        int HF1ANDda;
        int HF2ANDda;
	
	inTreeEm->SetBranchAddress("L1_MinimumBiasHF1_AND",&HF1ANDem);
	inTreeEm->SetBranchAddress("L1_MinimumBiasHF2_AND",&HF2ANDem);
	inTreeEm->SetBranchAddress("L1_MinimumBiasHF1_OR",&HF1ORem);
	inTreeEm->SetBranchAddress("L1_MinimumBiasHF2_OR",&HF2ORem);
	inTreeEm->SetBranchAddress("Event",&event);
	inTreeEm->SetBranchAddress("Run",&run);
	inTreeEm->SetBranchAddress("LumiBlock",&lumi);

	inTreeDa->SetBranchAddress("HF1OR",&HF1ORda);
        inTreeDa->SetBranchAddress("HF2OR",&HF2ORda);
        inTreeDa->SetBranchAddress("HF1AND",&HF1ANDda);
        inTreeDa->SetBranchAddress("HF2AND",&HF2ANDda);

	int nentries = inTreeEm->GetEntries();

	int iterHF1ORda = 0;
	int iterHF2ORda = 0;
	int iterHF1ANDda = 0;
	int iterHF2ANDda = 0;

	int iterHF1ORem = 0;
        int iterHF2ORem = 0;
        int iterHF1ANDem = 0;
        int iterHF2ANDem = 0;

	int iterHF1ORdaem = 0;
	int iterHF2ORdaem = 0;
	int iterHF1ANDdaem = 0;
	int iterHF2ANDdaem = 0;
	int iterMM = 0;

	for (int i = 0; i < nentries; i++)
	{
		inTreeDa->GetEntry(i);
		inTreeEm->GetEntry(i);

//		if (event == 379317069 || event == 378908034 || event == 378887488 || event == 379717343 || event == 379429998 || event == 378965873 || event == 379072999
//			|| event == 379152736 || event == 379180283 || event == 378850082 || event == 379344600 || event == 379252853 || event == 379070403 ||
//				event == 379195291 || event == 379177796 || event == 379142008)
//		{
//			std::cout << "Event: " << event << " HF1OREm: " << HF1ORem << " HF2OREm: " << HF2ORem << " HF1ANDEm: " << HF1ANDem << " HF2ANDEm: " << HF2ANDem << std::endl;
//		}
		if (HF1ORem == 1)
		{
			iterHF1ORem++;
		}
		if (HF2ORem == 1)
                 {
                         iterHF2ORem++;
                 }
         	if (HF1ANDem == 1)
                 {
                         iterHF1ANDem++;
                 }
         	if (HF2ANDem == 1)
                 {
                         iterHF2ANDem++;
                 }

		if (HF1ORda == 1)
		{
			iterHF1ORda++;
			if (HF1ORem == 1)
			{
				iterHF1ORdaem++;
			}
			else
			{
//			std::cout << "HF1ORdata: " << HF1ORda << " HF1OREm: " << HF1ORem << " Event: " << event << " Run: " << run << std::endl;
		//	std::cout << event << std::endl;
		//	iterMM++;
			}
		}
		if (HF2ORda == 1)
                  {
                          iterHF2ORda++;
                          if (HF2ORem == 1)
                          {
                                  iterHF2ORdaem++;
                          }
                	else
                          {
//                          std::cout << "HF2ORdata: " << HF2ORda << " HF2OREm: " << HF2ORem << " Event: " << event << " Run: " << run << std::endl;
                  //      	 std::cout << event << std::endl;
		//		iterMM++;
			  } 
			
		 }
  	    	if (HF1ANDda == 1)
                  {
                          iterHF1ANDda++;
                          if (HF1ANDem == 1)
                          {
                                  iterHF1ANDdaem++;
                          }
			else
                          {
//                          std::cout << "HF1ANDdata: " << HF1ANDda << " HF1ANDEm: " << HF1ANDem << " Event: " << event << " Run: " << run << std::endl;
                  //		 std::cout << event << std::endl;
		//		iterMM++;	
		        } 
                 }
     	 	if (HF2ANDda == 1)
                  {
                          iterHF2ANDda++;
                          if (HF2ANDem == 1)
                          {
                                  iterHF2ANDdaem++;
                          }
			else
                          {
//                          std::cout << "HF2ANDdata: " << HF2ANDda << " HF2ANDEm: " << HF2ANDem << " Event: " << event << " Run: " << run << std::endl;
        	//		 std::cout << event << std::endl; 
	       // 		iterMM++;  
		       }   
               }
	        if ((HF1ORda == 1 && HF1ORem == 0) || (HF2ORda == 1 && HF2ORem == 0) || (HF1ANDda == 1 && HF1ANDem == 0) || (HF2ANDda == 1 && HF2ANDem == 0))
			{
//				std::cout << event << " " << lumi << std::endl;
				iterMM++;
			}
	}
//	std::cout << iterMM << std::endl;
	std::cout << "Entries: " << nentries << std::endl; 
	std::cout << "HF1ORdata: " << iterHF1ORda << " HF1ORem: " << iterHF1ORem << " HF1ORdataandem: " << iterHF1ORdaem << " eff: " << (double)iterHF1ORdaem/(double)iterHF1ORda << std::endl;
	std::cout << "HF2ORdata: " << iterHF2ORda << " HF2ORem: " << iterHF2ORem << " HF2ORdataandem: " << iterHF2ORdaem << " eff: " << (double)iterHF2ORdaem/(double)iterHF2ORda << std::endl;
	std::cout << "HF1ANDdata: " << iterHF1ANDda << " HF1ANDem: " << iterHF1ANDem << " HF1ANDdataandem: " << iterHF1ANDdaem << " eff: " << (double)iterHF1ANDdaem/(double)iterHF1ANDda << std::endl;
	std::cout << "HF2ANDdata: " << iterHF2ANDda << " HF2ANDem: " << iterHF2ANDem << " HF2ANDdataandem: " << iterHF2ANDdaem << " eff: " << (double)iterHF2ANDdaem/(double)iterHF2ANDda << std::endl; 	
}
