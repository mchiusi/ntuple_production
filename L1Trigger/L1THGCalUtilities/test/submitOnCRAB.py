import sys
sys.path.append('.')
from CRABClient.UserUtilities import config
import local

config = config()

config.section_("General")
config.General.requestName = 'DoublePhoton_FlatPt-1To100_PU200_Phase2Fall22DRMiniAOD_{}_realbcstc_v2-v1'.format(local.prod_name)
config.General.workArea = 'jobs'

config.section_("JobType")
config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'testHGCalL1T_RelValV16_cfg.py'
config.JobType.maxMemoryMB = 2500

config.section_("Data")
config.Data.inputDataset = '/DoublePhoton_FlatPt-1To100-gun/Phase2Fall22DRMiniAOD-PU200_125X_mcRun4_realistic_v2-v1/GEN-SIM-DIGI-RAW-MINIAOD'
config.Data.inputDBS = 'global'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 10
config.Data.outLFNDirBase = local.outLFNDirBase
config.Data.publication = False
config.Data.outputDatasetTag = config.General.requestName

config.section_("Site")
config.Site.storageSite = local.storageSite
