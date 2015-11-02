# Auto generated configuration file
# using: 
# Revision: 1.19 
# Source: /local/reps/CMSSW/CMSSW/Configuration/Applications/python/ConfigBuilder.py,v 
# with command line options: reco -s RAW2DIGI --filein root://xrootd.unl.edu//store/data/Run2015C/ZeroBias2/RAW/v1/000/254/608/00000/04BAB119-4D47-E511-9BF5-02163E0123AE.root --fileout anOutputFileName.root --data --conditions 74X_dataRun2_Prompt_v1
import FWCore.ParameterSet.Config as cms

process = cms.Process('RAW2DIGI')

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff')
process.load('Configuration.StandardSequences.RawToDigi_Data_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(1)
)

# Input source
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
#	'root://xrootd.unl.edu//store/data/Run2015C/ZeroBias2/RAW/v1/000/254/608/00000/04BAB119-4D47-E511-9BF5-02163E0123AE.root'),
#   		'root://xrootd.unl.edu//store/data/Run2015C/ZeroBias1/RAW/v1/000/255/031/00000/026EE823-0A4C-E511-8315-02163E014742.root', 
#		'root://xrootd.unl.edu//store/data/Run2015C/ZeroBias1/RAW/v1/000/255/031/00000/04ADBC27-0A4C-E511-A6AB-02163E0139A4.root') 
		'file:/afs/cern.ch/work/m/mnorthup/private/MBTrigger/data/04ADBC27-0A4C-E511-A6AB-02163E0139A4.root')
 , secondaryFileNames = cms.untracked.vstring()
)

process.options = cms.untracked.PSet(

)

# Production Info
process.configurationMetadata = cms.untracked.PSet(
    annotation = cms.untracked.string('reco nevts:1'),
    name = cms.untracked.string('Applications'),
    version = cms.untracked.string('$Revision: 1.19 $')
)

# Output definition

process.RECOSIMoutput = cms.OutputModule("PoolOutputModule",
    dataset = cms.untracked.PSet(
        dataTier = cms.untracked.string(''),
        filterName = cms.untracked.string('')
    ),
    eventAutoFlushCompressedSize = cms.untracked.int32(5242880),
    fileName = cms.untracked.string('/afs/cern.ch/user/m/mnorthup/private/MBTrigger/HFBitEmulation/Data/Latest_1012015/IsolatedReleaseArea/CMSSW_7_6_0_pre4/src/rawdigioutput.root'),
#    outputCommands = process.RECOSIMEventContent.outputCommands,
    splitLevel = cms.untracked.int32(0)
)

# Additional output definition

# Other statements
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, '74X_dataRun2_Prompt_v1', '')

# Path and EndPath definitions
process.raw2digi_step = cms.Path(process.RawToDigi)
process.endjob_step = cms.EndPath(process.endOfProcess)
process.RECOSIMoutput_step = cms.EndPath(process.RECOSIMoutput)

# Schedule definition
process.schedule = cms.Schedule(process.raw2digi_step,process.endjob_step,process.RECOSIMoutput_step)


