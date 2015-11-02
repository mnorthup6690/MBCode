// -*- C++ -*-
//
// Package:    GTRet/GTBitsRet
// Class:      GTBitsRet
// 
/**\class GTBitsRet GTBitsRet.cc GTRet/GTBitsRet/plugins/GTBitsRet.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Michael Eugene Northup
//         Created:  Fri, 11 Sep 2015 10:54:13 GMT
//
//


// system include files
#include <memory>
#include <iostream>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "L1Trigger/GlobalTriggerAnalyzer/interface/L1GtUtils.h"

#include "DataFormats/Common/interface/ConditionsInEdm.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include "DataFormats/L1GlobalTrigger/interface/L1GlobalTriggerReadoutRecord.h"
#include "DataFormats/L1GlobalTrigger/interface/L1GlobalTriggerObjectMapRecord.h"
#include "DataFormats/L1GlobalTrigger/interface/L1GlobalTriggerObjectMaps.h"
#include "DataFormats/L1GlobalTrigger/interface/L1GtTriggerMenuLite.h"
#include "DataFormats/L1GlobalTrigger/interface/L1GlobalTriggerReadoutSetupFwd.h"
#include "DataFormats/HcalDigi/interface/HcalDigiCollections.h"

#include "FWCore/Common/interface/TriggerNames.h"
#include "DataFormats/Common/interface/TriggerResults.h"

#include "FWCore/Framework/interface/EventSetup.h"

#include "FWCore/Utilities/interface/EDGetToken.h"
#include "FWCore/Utilities/interface/InputTag.h"

#include "L1Trigger/GlobalTriggerAnalyzer/interface/L1GtUtils.h"
#include "L1Trigger/GlobalTriggerAnalyzer/interface/L1RetrieveL1Extra.h"
#include "TTree.h"
#include "TH2.h"
#include "L1Trigger/GlobalTriggerAnalyzer/interface/L1GtUtils.h"
#include "L1Trigger/L1TGlobal/interface/TriggerMenuFwd.h"
#include "CondFormats/L1TObjects/interface/L1GtTriggerMenu.h"
#include "CondFormats/DataRecord/interface/L1GtTriggerMenuRcd.h"
#include "FWCore/Framework/interface/ESHandle.h"

//
// class declaration
//

// If the analyzer does not use TFileService, please remove
// the template argument to the base class so the class inherits
// from  edm::one::EDAnalyzer<> and also remove the line from
// constructor "usesResource("TFileService");"
// This will improve performance in multithreaded jobs.

class GTBitsRet : public edm::one::EDAnalyzer<edm::one::SharedResources>  {
   public:
      explicit GTBitsRet(const edm::ParameterSet&);
      ~GTBitsRet();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

   private:
      virtual void beginJob() override;
      virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;

      // ----------member data ---------------------------
   private:
// L1GtUtils m_l1GtUtils;
//const AlgorithmMap* m_algorithmMap;
 
edm::InputTag L1GtReadoutRecordInputTag;
//edm::InputTag hcalDigisInputTag;
//edm::InputTag TriggerResults;
edm::EDGetTokenT<L1GlobalTriggerReadoutRecord> L1GTToken_;
//edm::EDGetTokenT<HcalTrigPrimDigiCollection> HcalTPsToken_;
//edm::EDGetTokenT<HFDigiCollection> HFDigisToken_;
//edm::EDGetTokenT<edm::TriggerResults> hlttoken_;
edm::Service<TFileService> fs;

// int bitCountHF1OR = 0;
// int bitCountHF2OR = 0;
// int bitCountHF1AND = 0;
// int bitCountHF2AND = 0;
// int eventTot = 0;

 TTree *MBBits;
 int HF1OR;
 int HF1AND;
 int HF2OR;
 int HF2AND;

// TH2I* FGBitHistoEmTot;
// TH2I* FGBitHistoDataTot;
 //TH2I* FGBitHistoEmEvent;
 //TH2I* FGBitHistoDataEvent;

   //  L1GtUtils m_l1GtUtils;
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//
/*
int convertFromTPGtoGCTeta(int& eta)
 {
        int neweta = 0;

	if (eta == -32)
	{
		neweta = 0;
	}
	if (eta == -31)
         {
                 neweta = 1;
         }
        if (eta == -30)
         {
                 neweta = 2;
         }
        if (eta == -29)
         {
                 neweta = 3;
         }

	if (eta == 29)
         {
                 neweta = 18;
         }
         if (eta == 30)
          {  
                  neweta = 19;
          }  
         if (eta == 31)
          {  
                  neweta = 20;
          }  
         if (eta == 32)
          {  
                  neweta = 21;
          }  


        return neweta;
}

int convertFromTPGtoGCTphi(int& phi)
 {
         int newphi = 0;
 
         if (phi == 1 || phi == 71)
          {
                  newphi = 0;
          }
          else if (phi == 3 || phi == 5)
            {
                  newphi = 1;
            }
          else if (phi == 7 || phi == 9)
            {
                  newphi = 2;
            }
          else if (phi == 11 || phi == 13)
            {
                  newphi = 3;
            }
          else if (phi == 15 || phi == 17)
            {
                  newphi = 4;
            }
          else if (phi == 19 || phi == 21)
            {
                  newphi = 5;
            }
          else if (phi == 23 || phi == 25)
            {
                  newphi = 6;
            }
          else if (phi == 27 || phi == 29)
            {
                  newphi = 7;
            }
          else if (phi == 31 || phi == 33)
            {
                  newphi = 8;
            }
          else if (phi == 35 || phi == 37)
            {
                  newphi = 9;
            }
          else if (phi == 39 || phi == 41)
            {
                  newphi = 10;
            }
          else if (phi == 43 || phi == 45)
            {
                  newphi = 11;
            }
          else if (phi == 47 || phi == 49)
            {
                  newphi = 12;
            }
          else if (phi == 51 || phi == 53)
             {
                  newphi = 13;
             }
          else if (phi == 55 || phi == 57)
             {
	              newphi = 14;
            }
          else if (phi == 59 || phi == 61)
             {
                  newphi = 15;
             }
          else if (phi == 63 || phi == 65)
             {
                  newphi = 16;
             }
          else if (phi == 67 || phi == 69)
             {
                  newphi = 17;
             }
                 return newphi;
 }

int convertFromFibertoGCTeta(int& eta)
{
	int neweta = 0;
 
          if (eta == 29 || eta == 30 || eta == 31)
          {
                 neweta = 18;
          }
          else if (eta == 32 || eta == 33 || eta == 34)
          {
                  neweta = 19;
          }
          else if (eta == 35 || eta == 36 || eta == 37)
          {
                  neweta = 20;
          }
          else if (eta == 38 || eta == 39 || eta == 40 || eta == 41)
          {
                  neweta = 21;
          }
          else if (eta == -29 || eta == -30 || eta == -31)
           {
                   neweta = 3;
           }
           else if (eta == -32 || eta == -33 || eta == -34)
           {
                   neweta = 2;
           }
           else if (eta == -35 || eta == -36 || eta == -37)
           {
                   neweta = 1;
           }
           else if (eta == -38 || eta == -39 || eta == -40 || eta == -41)
           {
                   neweta = 0;
           }
         return neweta;

}

int convertFromFibertoGCTphi(int& phi)
{
	int newphi = 0;

	 if (phi == 1 || phi == 71)
          {
                  newphi = 0;
          }
          else if (phi == 3 || phi == 5)
            {
                  newphi = 1;
            }
          else if (phi == 7 || phi == 9)
            {
                  newphi = 2;
            }
          else if (phi == 11 || phi == 13)
            {
                  newphi = 3;
            }
          else if (phi == 15 || phi == 17)
            {
                  newphi = 4;
            }
          else if (phi == 19 || phi == 21)
            {
                  newphi = 5;
            }
          else if (phi == 23 || phi == 25)
            {
                  newphi = 6;
            }
          else if (phi == 27 || phi == 29)
            {
                  newphi = 7;
            }
          else if (phi == 31 || phi == 33)
            {
                  newphi = 8;
            }
          else if (phi == 35 || phi == 37)
            {
                  newphi = 9;
            }
          else if (phi == 39 || phi == 41)
            {
                  newphi = 10;
            }
          else if (phi == 43 || phi == 45)
            {
                  newphi = 11;
            }
          else if (phi == 47 || phi == 49)
            {
                  newphi = 12;
            }
          else if (phi == 51 || phi == 53)
             {
                  newphi = 13;
             }
          else if (phi == 55 || phi == 57)
             {
                  newphi = 14;
	  }
          else if (phi == 59 || phi == 61)
             {
                  newphi = 15;
             }
          else if (phi == 63 || phi == 65)
             {
                  newphi = 16;
             }
          else if (phi == 67 || phi == 69)
             {
                  newphi = 17;
             }
                 return newphi;

}
*/
//
// constructors and destructor
//
GTBitsRet::GTBitsRet(const edm::ParameterSet& iConfig)

{
   //now do what ever initialization is needed
   usesResource("TFileService");
  //L1GtReadoutRecordInputTag  = iConfig.getParameter<edm::InputTag>("l1GtReadoutRecordInputTag");
  L1GTToken_ = consumes<L1GlobalTriggerReadoutRecord>(iConfig.getParameter< edm::InputTag >("l1GtReadoutRecordInputTag")); 
//  HcalTPsToken_ = consumes<HcalTrigPrimDigiCollection>(iConfig.getParameter< edm::InputTag >("hcalTPGInputTag"));
//  L1HcalDigis_ = consumes<L1GlobalTriggerReadoutRecord>(iConfig.getParameter< edm::InputTag >("l1GtReadoutRecordInputTag"));
// HFDigisToken_ = consumes<HFDigiCollection>(iConfig.getParameter< edm::InputTag >("HcalDigis_label"));
// hlttoken_ = consumes<edm::TriggerResults>(iConfig.getParameter< edm::InputTag >("TriggerResults"));
//FGBitHistoEmEvent = fs->make<TH2I>("FGBitEmEvent","FG Bit",22,0,22,18,0,18);
//FGBitHistoDataEvent = fs->make<TH2I>("FGBitDataEvent","FG Bit",22,0,22,18,0,18);
//  FGBitHisto = fs->make<TH2I>("FGBit","FG Bit",22,0,22,18,0,18);

}


GTBitsRet::~GTBitsRet()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
GTBitsRet::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;
   using namespace std;


	edm::Handle<L1GlobalTriggerReadoutRecord> gtReadoutRecord;

	iEvent.getByToken(L1GTToken_, gtReadoutRecord);	
	const DecisionWord& decWord = gtReadoutRecord->decisionWord();
	
int bitnum = 4;

HF1OR = decWord[bitnum];
HF2OR = decWord[bitnum+1];
HF1AND = decWord[bitnum+2];
HF2AND = decWord[bitnum+3];

MBBits->Fill();

/*
 edm::Handle<HcalTrigPrimDigiCollection> hcalTPs;
 edm::Handle<HFDigiCollection> hfDigis;
 
iEvent.getByToken(HFDigisToken_, hfDigis);
iEvent.getByToken(HcalTPsToken_, hcalTPs);

// Handle<edm::TriggerResults> hltresults;
// iEvent.getByToken(hlttoken_, hltresults);
 
 //   int ntrigs = hltresults->size();
 
//    edm::TriggerNames const& triggerNames = iEvent.triggerNames(*hltresults);
 
//    string pathName2 = "HLT_ZeroBias_part0_v1";
//    string pathName = "HLT_ZeroBias_v1";
//    string pathName3 = "HLT_L1MinimumBiasHF1OR_v1";
 
//    bool passTrig = hltresults->accept(triggerNames.triggerIndex(pathName));
//    bool passTrig2 = hltresults->accept(triggerNames.triggerIndex(pathName2));
//    bool passTrig3 = hltresults->accept(triggerNames.triggerIndex(pathName3));
//   std::cout << passTrig3 << std::endl;


int phiBin = 18;
int etaBin = 22;
int thresholds = 2;
 
int thresh1 = 12;
int thresh2 = 17;
 
int fiberQIEThresh[phiBin][etaBin][thresholds];
int FGBitEm[phiBin][etaBin];
 
 for (int i = 0; i < phiBin; i++)
 {
         for (int j = 0; j < etaBin; j++)
         {
                 FGBitEm[i][j] = 0;
                 for (int k = 0; k < thresholds; k++)
                 {
                         fiberQIEThresh[i][j][k] = 0;
                 }
         }
 }

int iter = 0;
for (HFDigiCollection::const_iterator hfdigi = hfDigis->begin(); hfdigi != hfDigis->end(); hfdigi++)
     {
         HcalDetId hcalid = HcalDetId(hfdigi->id()) ;

         int ietaFiber = hcalid.ieta();
         int iphiFiber = hcalid.iphi();
         int presample = hfdigi->presamples();
 
         double qieval = hfdigi->sample(presample).adc();
//       cout << "ietaFiber: " << ietaFiber << " iphiFiber: " << iphiFiber << " QIE: " << qieval << endl;
 
         int ietaGCT = convertFromFibertoGCTeta(ietaFiber);
         int iphiGCT = convertFromFibertoGCTphi(iphiFiber);
 
//       if (iphiGCT == 5 || iphiGCT == 6)
//	{      
        	iter++;
	       cout << "Iter: " << iter << " QIE: " << qieval << " ieta: " << ietaGCT << " iphi: " << iphiGCT << endl;
// 	}
         if (qieval > thresh1)
         {
                 fiberQIEThresh[iphiGCT][ietaGCT][0]++;
         }
         if (qieval > thresh2)
         {
                 fiberQIEThresh[iphiGCT][ietaGCT][1]++;
         }
    }

for (int i = 0; i < phiBin; i++)
         {
                 for (int j = 0; j < etaBin; j++)
                 {
                         if (fiberQIEThresh[i][j][0] > 0 && j < 4)
                         {
                                 FGBitEm[i][0] = 1;
                                 FGBitEm[i][2] = 1;
                         }
                         if (fiberQIEThresh[i][j][0] > 0 && j > 17)
                         {
                                 FGBitEm[i][19] = 1;
                                 FGBitEm[i][21] = 1;
                         }
                         if (fiberQIEThresh[i][j][1] > 0 && j < 4)
                         {
                                 FGBitEm[i][1] = 1;
                                 FGBitEm[i][3] = 1;
                      }
                         if (fiberQIEThresh[i][j][1] > 0 && j > 17)
                         {
                                 FGBitEm[i][18] = 1;
                                 FGBitEm[i][20] = 1;
                      }
                 }
         }
 
 int FGBitData[phiBin][etaBin];

  for (int i = 0; i < phiBin; i++)
	{
		for (int j = 0; j < etaBin; j++)
		{
			FGBitData[i][j] = 0;
		}
	}


   for (HcalTrigPrimDigiCollection::const_iterator itr = hcalTPs->begin(); itr != hcalTPs->end(); ++itr) {

     int ieta  = itr->id().ieta();
     int iphi  = itr->id().iphi();


	if (ieta > -29 && ieta < 29) continue;
//	std::cout << "ieta: " << ieta << " iphi: " << iphi << std::endl;
	int ietaGCT = convertFromTPGtoGCTeta(ieta);
	int iphiGCT = convertFromTPGtoGCTphi(iphi); 

//     HcalSubdetector subdet = (HcalSubdetector) 0;
//     if ( abs(ieta) <= 16 ) subdet = HcalSubdetector::HcalBarrel;
//     else if ( abs(ieta) <= 28 ) subdet = HcalSubdetector::HcalEndcap;
//     else if ( abs(ieta) <= 32 ) subdet = HcalSubdetector::HcalForward;

     bool fg = itr->SOI_fineGrain();
   std::cout << "ieta: " << ieta << " iphi: " << iphi << " FG: " << fg << std::endl;
	FGBitData[iphiGCT][ietaGCT] = fg;
}

for (int i = 0; i < phiBin; i++)
 {
         for (int j = 0; j < etaBin; j++)
         {
		FGBitHistoEmEvent->SetBinContent(j+1,i+1,0);
		FGBitHistoDataEvent->SetBinContent(j+1,i+1,0);

                 if (FGBitEm[i][j] == 1)
                 {
                         int binEm = FGBitHistoEmTot->GetBinContent(j+1,i+1);
                         FGBitHistoEmTot->SetBinContent(j+1,i+1,binEm+1);
             		 FGBitHistoEmEvent->SetBinContent(j+1,i+1,1);
	         }
		if (FGBitData[i][j] == 1)
      		{
			int binData = FGBitHistoDataTot->GetBinContent(j+1,i+1);
                        FGBitHistoDataTot->SetBinContent(j+1,i+1,binData+1);	
			FGBitHistoDataEvent->SetBinContent(j+1,i+1,1);
		}
	 }
 }
*/
#ifdef THIS_IS_AN_EVENT_EXAMPLE
   Handle<ExampleData> pIn;
   iEvent.getByLabel("example",pIn);
#endif
   
#ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
   ESHandle<SetupData> pSetup;
   iSetup.get<SetupRecord>().get(pSetup);
#endif
}


// ------------ method called once each job just before starting event loop  ------------
void 
GTBitsRet::beginJob()
{
/*
FGBitHistoEmTot = fs->make<TH2I>("FGBitEmTot","FG Bit",22,0,22,18,0,18);
FGBitHistoDataTot = fs->make<TH2I>("FGBitDataTot","FG Bit",22,0,22,18,0,18);

FGBitHistoEmEvent = fs->make<TH2I>("FGBitEmEvent","FG Bit",22,0,22,18,0,18);
FGBitHistoDataEvent = fs->make<TH2I>("FGBitDataEvent","FG Bit",22,0,22,18,0,18);
*/

MBBits = fs->make<TTree>("MBBits","Min Bias Bits");

MBBits->Branch("HF1OR",&HF1OR,"HF1OR/I");
MBBits->Branch("HF1AND",&HF1AND,"HF1AND/I");
MBBits->Branch("HF2OR",&HF2OR,"HF2OR/I");
MBBits->Branch("HF2AND",&HF2AND,"HF2AND/I");

}

// ------------ method called once each job just after ending the event loop  ------------
void 
GTBitsRet::endJob() 
{
//	using namespace std;
		
//	cout << "EventTot: " << eventTot << " HF1OR: " << bitCountHF1OR << " HF2OR: " << bitCountHF2OR << " HF1AND: " << bitCountHF1AND << " HF2AND: " << bitCountHF2AND << endl;
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
GTBitsRet::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(GTBitsRet);
