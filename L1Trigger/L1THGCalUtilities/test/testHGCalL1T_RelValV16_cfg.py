import FWCore.ParameterSet.VarParsing as VarParsing
import FWCore.ParameterSet.Config as cms

options = VarParsing.VarParsing ('analysis')
options.outputFile = 'NTuple.root'
options.inputFiles = []
options.parseArguments()

from Configuration.Eras.Era_Phase2C17I13M9_cff import Phase2C17I13M9
process = cms.Process('DIGI',Phase2C17I13M9)

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('SimGeneral.MixingModule.mixNoPU_cfi')
process.load('Configuration.Geometry.GeometryExtended2026D88Reco_cff')
process.load('Configuration.Geometry.GeometryExtended2026D88_cff')
process.load('Configuration.StandardSequences.MagneticField_cff')
process.load('Configuration.StandardSequences.Generator_cff')
process.load('IOMC.EventVertexGenerators.VtxSmearedHLLHC14TeV_cfi')
process.load('GeneratorInterface.Core.genFilterSummary_cff')
process.load('Configuration.StandardSequences.SimIdeal_cff')
process.load('Configuration.StandardSequences.Digi_cff')
process.load('Configuration.StandardSequences.SimL1Emulator_cff')
process.load('Configuration.StandardSequences.DigiToRaw_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')


process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

# Input source
process.source = cms.Source("PoolSource",
       # dummy file
       # fileNames = cms.untracked.vstring('/store/mc/Phase2Fall22DRMiniAOD/TT_TuneCP5_14TeV-powheg-pythia8/GEN-SIM-DIGI-RAW-MINIAOD/PU200_125X_mcRun4_realistic_v2_ext1-v1/30000/000c5e5f-78f7-44ee-95fe-7b2f2c2e2312.root'),
       fileNames = cms.untracked.vstring('root://se01.indiacms.res.in//dpm/indiacms.res.in/home/cms/store/mc/Phase2Fall22DRMiniAOD/DoublePhoton_FlatPt-1To100-gun/GEN-SIM-DIGI-RAW-MINIAOD/PU200_125X_mcRun4_realistic_v2-v1/30000/0075a153-cb64-4ed9-9157-a1b6db9fd431.root'),
       # fileNames = cms.untracked.vstring('davs://eosctacms.cern.ch:8444//eos/ctacms/archive/cms/store/mc/Phase2Fall22DRMiniAOD/SinglePhoton_Pt-2To200-gun/GEN-SIM-DIGI-RAW-MINIAOD/noPU_125X_mcRun4_realistic_v2-v1/2560000/0116edbb-b12b-45a9-b8b4-0e603466dc3b.root'),
       inputCommands=cms.untracked.vstring(
           'keep *',
           )
        )
process.options = cms.untracked.PSet(

)

if options.inputFiles:
    process.source.fileNames = cms.untracked.vstring(options.inputFiles)

# Production Info
process.configurationMetadata = cms.untracked.PSet(
    version = cms.untracked.string('$Revision: 1.20 $'),
    annotation = cms.untracked.string('SingleElectronPt10_cfi nevts:10'),
    name = cms.untracked.string('Applications')
)

# Output definition
process.TFileService = cms.Service(
    "TFileService",
    fileName = cms.string(options.outputFile)
    )

# Other statements
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, 'auto:phase2_realistic_T21', '')

# load HGCAL TPG simulation
process.load('L1Trigger.L1THGCal.hgcalTriggerPrimitives_cff')

from L1Trigger.L1THGCal.l1tHGCalConcentratorProducer_cfi import custom_conc_proc
parameters = custom_conc_proc.clone(stcSize = custom_conc_proc.stcSize,
                                    type_energy_division = custom_conc_proc.type_energy_division,
                                    fixedDataSizePerHGCROC = custom_conc_proc.fixedDataSizePerHGCROC,
                                    Method = cms.vstring('thresholdSelect','superTriggerCellSelect','superTriggerCellSelect'),        
)
process.l1tHGCalConcentratorProducer.ProcessorParameters = parameters
process.hgcl1tpg_step = cms.Path(process.L1THGCalTriggerPrimitives)


# load ntuplizer
process.load('L1Trigger.L1THGCalUtilities.hgcalTriggerNtuples_cff')
process.ntuple_step = cms.Path(process.L1THGCalTriggerNtuples)

# Schedule definition
process.schedule = cms.Schedule(process.hgcl1tpg_step, process.ntuple_step)

# Add early deletion of temporary data products to reduce peak memory need
from Configuration.StandardSequences.earlyDeleteSettings_cff import customiseEarlyDelete
process = customiseEarlyDelete(process)
# End adding early deletion
