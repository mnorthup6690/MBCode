import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")
process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(1) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
#        'root://xrootd.unl.edu//store/data/Run2015A/ZeroBias1/RECO/PromptReco-v1/000/247/324/00000/02BDFA64-B40E-E511-8CB7-02163E012ACF.root'
#		'root://xrootd.unl.edu//store/data/Run2015C/ZeroBias1/RECO/PromptReco-v1/000/255/031/00000/0A00ECC1-444E-E511-8B91-02163E012867.root' 
#		'root://xrootd.unl.edu//store/data/Run2015C/ZeroBias2/RECO/PromptReco-v1/000/254/608/00000/6E76DAA7-F048-E511-A93B-02163E0146B3.root'
#		'root://xrootd.unl.edu//store/data/Run2015C/ZeroBias2/RAW/v1/000/254/608/00000/04BAB119-4D47-E511-9BF5-02163E0123AE.root'
#		'file:/afs/cern.ch/user/m/mnorthup/private/MBTrigger/HFBitEmulation/Data/Latest_1012015/CMSSW_7_6_0_pre4/src/GTRet/GTBitsRet/python/anOutputFileName.root'
#  		'file:/afs/cern.ch/user/m/mnorthup/private/MBTrigger/HFBitEmulation/Data/Latest_1012015/IsolatedReleaseArea/CMSSW_7_6_0_pre4/src/anOutputFileName.root'
#		'file:/afs/cern.ch/user/m/mnorthup/private/MBTrigger/HFBitEmulation/Data/Latest_1012015/IsolatedReleaseArea/CMSSW_7_6_0_pre4/src/anOutputFileName_10.root'
#		'file:/afs/cern.ch/user/m/mnorthup/private/MBTrigger/HFBitEmulation/Data/Latest_1012015/IsolatedReleaseArea/CMSSW_7_6_0_pre4/src/anOutputFileName_100.root'
#		'file:///afs/cern.ch/work/m/mnorthup/private/MBTrigger/anOutputFileName_34000.root'
#		'file:/afs/cern.ch/work/m/mnorthup/private/MBTrigger/run255031_04ADBC27_1000.root'
		'file:/afs/cern.ch/work/m/mnorthup/private/MBTrigger/run255031_04ADBC27_10000.root'
#		'file:///afs/cern.ch/work/m/mnorthup/private/MBTrigger/run255031_04ADBC27_34000_v2.root'
   )
#	,	eventsToProcess = cms.untracked.VEventRange('255031:379142008')
)

process.demo = cms.EDAnalyzer('GTBitsRet'
#,	TriggerResults = cms.InputTag("TriggerResults", "", "HLT") 
,	l1GtReadoutRecordInputTag = cms.InputTag("gtDigis", "", "RAW2DIGI")
#,	hcalTPGInputTag = cms.InputTag("hcalDigis", "", "RAW2DIGI")
#,	HcalDigis_label = cms.InputTag("hcalDigis", "", "RAW2DIGI")
)

#process.TFileService = cms.Service("TFileService",
#                                       fileName = cms.string('treeMBBits.root')
#                                   )

process.TFileService = cms.Service("TFileService",
          fileName = cms.string('histo.root')
     )

process.p = cms.Path(process.demo)
