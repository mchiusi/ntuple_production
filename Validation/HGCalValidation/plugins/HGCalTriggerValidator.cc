// system include files
#include <memory>
#include <iostream>
#include <string>
#include <vector>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/Event.h"
#include "DataFormats/Common/interface/Handle.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Utilities/interface/ESGetToken.h"

#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Common/interface/Provenance.h"

#include <DQMServices/Core/interface/DQMStore.h>
#include "DQMServices/Core/interface/DQMGlobalEDAnalyzer.h"

#include "DataFormats/ForwardDetId/interface/HGCalDetId.h"
#include "DataFormats/L1THGCal/interface/HGCalTriggerCell.h"
#include "DataFormats/L1THGCal/interface/HGCalCluster.h"
#include "DataFormats/L1THGCal/interface/HGCalMulticluster.h"
#include "DataFormats/L1THGCal/interface/HGCalTower.h"

#include "Geometry/Records/interface/CaloGeometryRecord.h"
#include "L1Trigger/L1THGCal/interface/HGCalTriggerGeometryBase.h"
#include "L1Trigger/L1THGCal/interface/HGCalTriggerTools.h"
#include "L1Trigger/L1THGCal/interface/backend/HGCalTriggerClusterIdentificationBase.h"

//
// class declaration
//

struct Histograms {
  //histogram tc related
  dqm::reco::MonitorElement *h_tc_n_;
  dqm::reco::MonitorElement *h_tc_mipPt_;
  dqm::reco::MonitorElement *h_tc_pt_;
  dqm::reco::MonitorElement *h_tc_energy_;
  dqm::reco::MonitorElement *h_tc_eta_;
  dqm::reco::MonitorElement *h_tc_phi_;
  dqm::reco::MonitorElement *h_tc_x_;
  dqm::reco::MonitorElement *h_tc_y_;
  dqm::reco::MonitorElement *h_tc_z_;
  dqm::reco::MonitorElement *h_tc_layer_;

  //histogram cl related
  dqm::reco::MonitorElement *h_cl_n_;
  dqm::reco::MonitorElement *h_cl_mipPt_;
  dqm::reco::MonitorElement *h_cl_pt_;
  dqm::reco::MonitorElement *h_cl_energy_;
  dqm::reco::MonitorElement *h_cl_eta_;
  dqm::reco::MonitorElement *h_cl_phi_;
  dqm::reco::MonitorElement *h_cl_layer_;
  dqm::reco::MonitorElement *h_cl_cells_n_;

  //histogram multicl related
  dqm::reco::MonitorElement *h_cl3d_n_;
  dqm::reco::MonitorElement *h_cl3d_pt_;
  dqm::reco::MonitorElement *h_cl3d_energy_;
  dqm::reco::MonitorElement *h_cl3d_eta_;
  dqm::reco::MonitorElement *h_cl3d_phi_;
  dqm::reco::MonitorElement *h_cl3d_clusters_n_;
  // cluster shower shapes
  dqm::reco::MonitorElement *h_cl3d_showerlength_;
  dqm::reco::MonitorElement *h_cl3d_coreshowerlength_;
  dqm::reco::MonitorElement *h_cl3d_firstlayer_;
  dqm::reco::MonitorElement *h_cl3d_maxlayer_;
  dqm::reco::MonitorElement *h_cl3d_seetot_;
  dqm::reco::MonitorElement *h_cl3d_seemax_;
  dqm::reco::MonitorElement *h_cl3d_spptot_;
  dqm::reco::MonitorElement *h_cl3d_sppmax_;
  dqm::reco::MonitorElement *h_cl3d_szz_;
  dqm::reco::MonitorElement *h_cl3d_srrtot_;
  dqm::reco::MonitorElement *h_cl3d_srrmax_;
  dqm::reco::MonitorElement *h_cl3d_srrmean_;
  dqm::reco::MonitorElement *h_cl3d_emaxe_;
  dqm::reco::MonitorElement *h_cl3d_hoe_;
  dqm::reco::MonitorElement *h_cl3d_meanz_;
  dqm::reco::MonitorElement *h_cl3d_layer10_;
  dqm::reco::MonitorElement *h_cl3d_layer50_;
  dqm::reco::MonitorElement *h_cl3d_layer90_;
  dqm::reco::MonitorElement *h_cl3d_first1layers_;
  dqm::reco::MonitorElement *h_cl3d_first3layers_;
  dqm::reco::MonitorElement *h_cl3d_first5layers_;
  dqm::reco::MonitorElement *h_cl3d_firstHcal1layers_;
  dqm::reco::MonitorElement *h_cl3d_firstHcal3layers_;
  dqm::reco::MonitorElement *h_cl3d_firstHcal5layers_;
  dqm::reco::MonitorElement *h_cl3d_last1layers_;
  dqm::reco::MonitorElement *h_cl3d_last3layers_;
  dqm::reco::MonitorElement *h_cl3d_last5layers_;
  dqm::reco::MonitorElement *h_cl3d_emax1layers_;
  dqm::reco::MonitorElement *h_cl3d_emax3layers_;
  dqm::reco::MonitorElement *h_cl3d_emax5layers_;
  dqm::reco::MonitorElement *h_cl3d_eot_;
  dqm::reco::MonitorElement *h_cl3d_ebm0_;
  dqm::reco::MonitorElement *h_cl3d_ebm1_;
  dqm::reco::MonitorElement *h_cl3d_hbm_;
  dqm::reco::MonitorElement *h_cl3d_ntc67_;
  dqm::reco::MonitorElement *h_cl3d_ntc90_;
  dqm::reco::MonitorElement *h_cl3d_bdteg_;
  dqm::reco::MonitorElement *h_cl3d_quality_;

  //histogram tower related
  dqm::reco::MonitorElement *h_tower_n_;
  dqm::reco::MonitorElement *h_tower_pt_;
  dqm::reco::MonitorElement *h_tower_energy_;
  dqm::reco::MonitorElement *h_tower_eta_;
  dqm::reco::MonitorElement *h_tower_phi_;
  dqm::reco::MonitorElement *h_tower_etEm_;
  dqm::reco::MonitorElement *h_tower_etHad_;
  dqm::reco::MonitorElement *h_tower_iEta_;
  dqm::reco::MonitorElement *h_tower_iPhi_;
};

class HGCalTriggerValidator : public DQMGlobalEDAnalyzer<Histograms> {
public:
  explicit HGCalTriggerValidator(const edm::ParameterSet &);
  ~HGCalTriggerValidator() override = default;

private:
  void dqmBeginRun(edm::Run const &, edm::EventSetup const &, Histograms &) const override;
  void bookHistograms(DQMStore::IBooker &, edm::Run const &, edm::EventSetup const &, Histograms &) const override;
  void dqmAnalyze(edm::Event const &, edm::EventSetup const &, Histograms const &) const override;

private:
  // ----------member data ---------------------------
  const edm::EDGetToken trigger_cells_token_;
  const edm::EDGetToken clusters_token_;
  const edm::EDGetToken multiclusters_token_;
  const edm::EDGetToken towers_token_;
  const edm::ESGetToken<HGCalTriggerGeometryBase, CaloGeometryRecord> triggerGeomToken_;

  std::unique_ptr<HGCalTriggerClusterIdentificationBase> id_;

  std::shared_ptr<HGCalTriggerTools> triggerTools_;
};

HGCalTriggerValidator::HGCalTriggerValidator(const edm::ParameterSet &iConfig)
    : trigger_cells_token_{consumes<l1t::HGCalTriggerCellBxCollection>(
          iConfig.getParameter<edm::InputTag>("TriggerCells"))},
      clusters_token_{consumes<l1t::HGCalClusterBxCollection>(iConfig.getParameter<edm::InputTag>("Clusters"))},
      multiclusters_token_{
          consumes<l1t::HGCalMulticlusterBxCollection>(iConfig.getParameter<edm::InputTag>("Multiclusters"))},
      towers_token_{consumes<l1t::HGCalTowerBxCollection>(iConfig.getParameter<edm::InputTag>("Towers"))},
      triggerGeomToken_(esConsumes<HGCalTriggerGeometryBase, CaloGeometryRecord, edm::Transition::BeginRun>()),
      id_{HGCalTriggerClusterIdentificationFactory::get()->create("HGCalTriggerClusterIdentificationBDT")} {
  id_->initialize(iConfig.getParameter<edm::ParameterSet>("EGIdentification"));

  triggerTools_ = std::make_shared<HGCalTriggerTools>();
}

void HGCalTriggerValidator::dqmBeginRun(edm::Run const &iRun,
                                        edm::EventSetup const &iSetup,
                                        Histograms &histograms) const {
  auto const triggerGeometry = iSetup.getHandle(triggerGeomToken_);
  triggerTools_->setGeometry(triggerGeometry.product());
}

void HGCalTriggerValidator::bookHistograms(DQMStore::IBooker &iBooker,
                                           edm::Run const &,
                                           edm::EventSetup const &iSetup,
                                           Histograms &histograms) const {
  iBooker.cd();
  iBooker.setCurrentFolder("HGCALTPG");

  //initiating histograms
  // trigger cells
  histograms.h_tc_n_ = iBooker.book1D("tc_n", "trigger cell number; number", 100, 10000, 40000);
  histograms.h_tc_mipPt_ = iBooker.book1D("tc_mipPt", "trigger cell mipPt; mipPt", 100, 0, 10);
  histograms.h_tc_pt_ = iBooker.book1D("tc_pt", "trigger cell pt; pt [GeV]", 100, 0, 2);
  histograms.h_tc_energy_ = iBooker.book1D("tc_energy", "trigger cell energy; energy [GeV]", 100, 0, 5);
  histograms.h_tc_eta_ = iBooker.book1D("tc_eta", "trigger cell eta; eta", 320, -3.2, 3.2);
  histograms.h_tc_phi_ = iBooker.book1D("tc_phi", "trigger cell phi; phi", 100, -M_PI, M_PI);
  histograms.h_tc_x_ = iBooker.book1D("tc_x", "trigger cell x; x [cm]", 100, -250, 250);
  histograms.h_tc_y_ = iBooker.book1D("tc_y", "trigger cell y; y [cm]", 100, -250, 250);
  histograms.h_tc_z_ = iBooker.book1D("tc_z", "trigger cell z; z [cm]", 100, -550, 550);
  histograms.h_tc_layer_ = iBooker.book1D("tc_layer", "trigger cell layer; layer", 50, 0, 50);

  // cluster 2D histograms
  histograms.h_cl_n_ = iBooker.book1D("cl_n", "cluster2D number; number", 100, 10000, 40000);
  histograms.h_cl_mipPt_ = iBooker.book1D("cl_mipPt", "cluster2D mipPt; mipPt", 100, 0, 10);
  histograms.h_cl_pt_ = iBooker.book1D("cl_pt", "cluster2D pt; pt [GeV]", 100, 0, 2);
  histograms.h_cl_energy_ = iBooker.book1D("cl_energy", "cluster2D energy; energy [GeV]", 100, 0, 5);
  histograms.h_cl_eta_ = iBooker.book1D("cl_eta", "cluster2D eta; eta", 320, -3.2, 3.2);
  histograms.h_cl_phi_ = iBooker.book1D("cl_phi", "cluster2D phi; phi", 100, -M_PI, M_PI);
  histograms.h_cl_cells_n_ = iBooker.book1D("cl_cells_n", "cluster2D cells_n; cells_n", 20, 0, 20);
  histograms.h_cl_layer_ = iBooker.book1D("cl_layer", "cluster2D layer; layer", 50, 0, 50);

  // multiclusters
  histograms.h_cl3d_n_ = iBooker.book1D("cl3d_n", "cl3duster3D number; number", 200, 0, 400);
  histograms.h_cl3d_pt_ = iBooker.book1D("cl3d_pt", "cl3duster3D pt; pt [GeV]", 50, 0, 50);
  histograms.h_cl3d_energy_ = iBooker.book1D("cl3d_energy", "cl3duster3D energy; energy [GeV]", 50, 0, 200);
  histograms.h_cl3d_eta_ = iBooker.book1D("cl3d_eta", "cl3duster3D eta; eta", 320, -3.2, 3.2);
  histograms.h_cl3d_phi_ = iBooker.book1D("cl3d_phi", "cl3duster3D phi; phi", 100, -M_PI, M_PI);
  histograms.h_cl3d_clusters_n_ = iBooker.book1D("cl3d_clusters_n", "cl3duster3D clusters_n; clusters_n", 50, 0, 200);
  // cluster shower shapes
  histograms.h_cl3d_showerlength_ =
      iBooker.book1D("cl3d_showerlength", "cl3duster3D showerlength; showerlength", 50, 0, 50);
  histograms.h_cl3d_coreshowerlength_ =
      iBooker.book1D("cl3d_coreshowerlength", "cl3duster3D coreshowerlength; coreshowerlength", 20, 0, 20);
  histograms.h_cl3d_firstlayer_ = iBooker.book1D("cl3d_firstlayer", "cl3duster3D firstlayer; firstlayer", 10, 0, 10);
  histograms.h_cl3d_maxlayer_ = iBooker.book1D("cl3d_maxlayer", "cl3duster3D maxlayer; maxlayer", 50, 0, 50);
  histograms.h_cl3d_seetot_ = iBooker.book1D("cl3d_seetot", "cl3duster3D seetot; seetot", 50, 0, 0.1);
  histograms.h_cl3d_seemax_ = iBooker.book1D("cl3d_seemax", "cl3duster3D seemax; seemax", 50, 0, 0.2);
  histograms.h_cl3d_spptot_ = iBooker.book1D("cl3d_spptot", "cl3duster3D spptot; spptot", 50, 0, 0.1);
  histograms.h_cl3d_sppmax_ = iBooker.book1D("cl3d_sppmax", "cl3duster3D sppmax; sppmax", 50, 0, 0.15);
  histograms.h_cl3d_szz_ = iBooker.book1D("cl3d_szz", "cl3duster3D szz; szz", 50, 0, 80);
  histograms.h_cl3d_srrtot_ = iBooker.book1D("cl3d_srrtot", "cl3duster3D srrtot; srrtot", 50, 0, 0.01);
  histograms.h_cl3d_srrmax_ = iBooker.book1D("cl3d_srrmax", "cl3duster3D srrmax; srrmax", 50, 0, 0.014);
  histograms.h_cl3d_srrmean_ = iBooker.book1D("cl3d_srrmean", "cl3duster3D srrmean; srrmean", 50, 0, 0.006);
  histograms.h_cl3d_emaxe_ = iBooker.book1D("cl3d_emaxe", "cl3duster3D emaxe; emaxe", 50, 0, 1.01);
  histograms.h_cl3d_hoe_ = iBooker.book1D("cl3d_hoe", "cl3duster3D hoe; hoe", 50, 0, 2.);
  histograms.h_cl3d_meanz_ = iBooker.book1D("cl3d_meanz", "cl3duster3D meanz; meanz", 50, 300, 400);
  histograms.h_cl3d_layer10_ = iBooker.book1D("cl3d_layer10", "cl3duster3D layer10; layer10", 10, 0, 10);
  histograms.h_cl3d_layer50_ = iBooker.book1D("cl3d_layer50", "cl3duster3D layer50; layer50", 20, 0, 20);
  histograms.h_cl3d_layer90_ = iBooker.book1D("cl3d_layer90", "cl3duster3D layer90; layer90", 40, 0, 40);
  histograms.h_cl3d_first1layers_ =
      iBooker.book1D("cl3d_first1layers", "cl3duster3D first1layers; first1layers", 50, 0, 1.01);
  histograms.h_cl3d_first3layers_ =
      iBooker.book1D("cl3d_first3layers", "cl3duster3D first3layers; first3layers", 50, 0, 1.01);
  histograms.h_cl3d_first5layers_ =
      iBooker.book1D("cl3d_first5layers", "cl3duster3D first5layers; first5layers", 50, 0, 1.01);
  histograms.h_cl3d_firstHcal1layers_ =
      iBooker.book1D("cl3d_firstHcal1layers", "cl3duster3D firstHcal1layers; hcal1layers", 50, 0, 0.5);
  histograms.h_cl3d_firstHcal3layers_ =
      iBooker.book1D("cl3d_firstHcal3layers", "cl3duster3D firstHcal3layers; hcal1layers", 50, 0, 0.5);
  histograms.h_cl3d_firstHcal5layers_ =
      iBooker.book1D("cl3d_firstHcal5layers", "cl3duster3D firstHcal5layers; hcal1layers", 50, 0, 0.5);
  histograms.h_cl3d_last1layers_ =
      iBooker.book1D("cl3d_last1layers", "cl3duster3D last1layers; last1layers", 50, 0, 0.1);
  histograms.h_cl3d_last3layers_ =
      iBooker.book1D("cl3d_last3layers", "cl3duster3D last3layers; last3layers", 50, 0, 0.1);
  histograms.h_cl3d_last5layers_ =
      iBooker.book1D("cl3d_last5layers", "cl3duster3D last5layers; last5layers", 50, 0, 0.1);
  histograms.h_cl3d_emax1layers_ =
      iBooker.book1D("cl3d_emax1layers", "cl3duster3D emax1layers; emax1layers", 50, 0, 1.01);
  histograms.h_cl3d_emax3layers_ =
      iBooker.book1D("cl3d_emax3layers", "cl3duster3D emax3layers; emax3layers", 50, 0, 1.01);
  histograms.h_cl3d_emax5layers_ =
      iBooker.book1D("cl3d_emax5layers", "cl3duster3D emax5layers; emax5layers", 50, 0, 1.01);
  histograms.h_cl3d_eot_ = iBooker.book1D("cl3d_eot", "cl3duster3D eot; eot", 50, 0, 1.01);
  histograms.h_cl3d_ebm0_ = iBooker.book1D("cl3d_ebm0", "cl3duster3D ebm0; ebm0", 50, 0, 9000);
  histograms.h_cl3d_ebm1_ = iBooker.book1D("cl3d_ebm1", "cl3duster3D ebm1; ebm1", 50, 0, 9000);
  histograms.h_cl3d_hbm_ = iBooker.book1D("cl3d_hbm", "cl3duster3D hbm; hbm", 50, 0, 4000);
  histograms.h_cl3d_ntc67_ = iBooker.book1D("cl3d_ntc67", "cl3duster3D ntc67; ntc67", 50, 0, 50);
  histograms.h_cl3d_ntc90_ = iBooker.book1D("cl3d_ntc90", "cl3duster3D ntc90; ntc90", 50, 0, 100);
  histograms.h_cl3d_bdteg_ = iBooker.book1D("cl3d_bdteg", "cl3duster3D bdteg; bdteg", 50, -1., 1.);
  histograms.h_cl3d_quality_ = iBooker.book1D("cl3d_quality", "cl3duster3D quality; quality", 5, 0, 5);

  // towers
  histograms.h_tower_n_ = iBooker.book1D("tower_n", "tower n; number", 100, 2000, 3000);
  histograms.h_tower_pt_ = iBooker.book1D("tower_pt", "tower pt; pt [GeV]", 100, 0, 10);
  histograms.h_tower_energy_ = iBooker.book1D("tower_energy", "tower energy; energy [GeV]", 100, 0, 100);
  histograms.h_tower_eta_ = iBooker.book1D("tower_eta", "tower eta; eta", 640, -3.2, 3.2);
  histograms.h_tower_phi_ = iBooker.book1D("tower_phi", "tower phi; phi", 600, -M_PI, M_PI);
  histograms.h_tower_etEm_ = iBooker.book1D("tower_etEm", "tower etEm; etEm", 100, 0, 10);
  histograms.h_tower_etHad_ = iBooker.book1D("tower_etHad", "tower etHad; etHad", 100, 0, 5);
  histograms.h_tower_iEta_ = iBooker.book1D("tower_iEta", "tower iEta; iEta", 20, 0, 20);
  histograms.h_tower_iPhi_ = iBooker.book1D("tower_iPhi", "tower iPhi; iPhi", 80, 0, 80);
}

void HGCalTriggerValidator::dqmAnalyze(edm::Event const &iEvent,
                                       edm::EventSetup const &iSetup,
                                       Histograms const &histograms) const {
  int tc_n = 0;
  int cl_n = 0;
  int cl3d_n = 0;
  int tower_n = 0;

  // retrieve trigger cells
  edm::Handle<l1t::HGCalTriggerCellBxCollection> trigger_cells_h;
  iEvent.getByToken(trigger_cells_token_, trigger_cells_h);
  const l1t::HGCalTriggerCellBxCollection &trigger_cells = *trigger_cells_h;

  if (trigger_cells_h.isValid()) {
    for (auto tc_itr = trigger_cells.begin(0); tc_itr != trigger_cells.end(0); tc_itr++) {
      tc_n++;
      HGCalDetId id(tc_itr->detId());
      histograms.h_tc_pt_->Fill(tc_itr->pt());
      histograms.h_tc_mipPt_->Fill(tc_itr->mipPt());
      histograms.h_tc_energy_->Fill(tc_itr->energy());
      histograms.h_tc_eta_->Fill(tc_itr->eta());
      histograms.h_tc_phi_->Fill(tc_itr->phi());
      histograms.h_tc_x_->Fill(tc_itr->position().x());
      histograms.h_tc_y_->Fill(tc_itr->position().y());
      histograms.h_tc_z_->Fill(tc_itr->position().z());
      histograms.h_tc_layer_->Fill(triggerTools_->layerWithOffset(id));
    }
  }
  histograms.h_tc_n_->Fill(tc_n);

  // retrieve clusters
  edm::Handle<l1t::HGCalClusterBxCollection> clusters_h;
  iEvent.getByToken(clusters_token_, clusters_h);
  const l1t::HGCalClusterBxCollection &clusters = *clusters_h;

  if (clusters_h.isValid()) {
    for (auto cl_itr = clusters.begin(0); cl_itr != clusters.end(0); cl_itr++) {
      cl_n++;
      histograms.h_cl_mipPt_->Fill(cl_itr->mipPt());
      histograms.h_cl_pt_->Fill(cl_itr->pt());
      histograms.h_cl_energy_->Fill(cl_itr->energy());
      histograms.h_cl_eta_->Fill(cl_itr->eta());
      histograms.h_cl_phi_->Fill(cl_itr->phi());
      histograms.h_cl_layer_->Fill(triggerTools_->layerWithOffset(cl_itr->detId()));
      histograms.h_cl_cells_n_->Fill(cl_itr->constituents().size());
    }
  }
  histograms.h_cl_n_->Fill(cl_n);

  // retrieve clusters 3D
  edm::Handle<l1t::HGCalMulticlusterBxCollection> multiclusters_h;
  iEvent.getByToken(multiclusters_token_, multiclusters_h);
  const l1t::HGCalMulticlusterBxCollection &multiclusters = *multiclusters_h;

  if (multiclusters_h.isValid()) {
    for (auto cl3d_itr = multiclusters.begin(0); cl3d_itr != multiclusters.end(0); cl3d_itr++) {
      cl3d_n++;
      histograms.h_cl3d_pt_->Fill(cl3d_itr->pt());
      histograms.h_cl3d_energy_->Fill(cl3d_itr->energy());
      histograms.h_cl3d_eta_->Fill(cl3d_itr->eta());
      histograms.h_cl3d_phi_->Fill(cl3d_itr->phi());
      histograms.h_cl3d_clusters_n_->Fill(cl3d_itr->constituents().size());
      // cluster shower shapes
      histograms.h_cl3d_showerlength_->Fill(cl3d_itr->showerLength());
      histograms.h_cl3d_coreshowerlength_->Fill(cl3d_itr->coreShowerLength());
      histograms.h_cl3d_firstlayer_->Fill(cl3d_itr->firstLayer());
      histograms.h_cl3d_maxlayer_->Fill(cl3d_itr->maxLayer());
      histograms.h_cl3d_seetot_->Fill(cl3d_itr->sigmaEtaEtaTot());
      histograms.h_cl3d_seemax_->Fill(cl3d_itr->sigmaEtaEtaMax());
      histograms.h_cl3d_spptot_->Fill(cl3d_itr->sigmaPhiPhiTot());
      histograms.h_cl3d_sppmax_->Fill(cl3d_itr->sigmaPhiPhiMax());
      histograms.h_cl3d_szz_->Fill(cl3d_itr->sigmaZZ());
      histograms.h_cl3d_srrtot_->Fill(cl3d_itr->sigmaRRTot());
      histograms.h_cl3d_srrmax_->Fill(cl3d_itr->sigmaRRMax());
      histograms.h_cl3d_srrmean_->Fill(cl3d_itr->sigmaRRMean());
      histograms.h_cl3d_emaxe_->Fill(cl3d_itr->eMax() / cl3d_itr->energy());
      histograms.h_cl3d_hoe_->Fill(cl3d_itr->hOverE());
      histograms.h_cl3d_meanz_->Fill(cl3d_itr->zBarycenter());
      histograms.h_cl3d_layer10_->Fill(cl3d_itr->layer10percent());
      histograms.h_cl3d_layer50_->Fill(cl3d_itr->layer50percent());
      histograms.h_cl3d_layer90_->Fill(cl3d_itr->layer90percent());
      histograms.h_cl3d_first1layers_->Fill(cl3d_itr->first1layers());
      histograms.h_cl3d_first3layers_->Fill(cl3d_itr->first3layers());
      histograms.h_cl3d_first5layers_->Fill(cl3d_itr->first5layers());
      histograms.h_cl3d_firstHcal1layers_->Fill(cl3d_itr->firstHcal1layers());
      histograms.h_cl3d_firstHcal3layers_->Fill(cl3d_itr->firstHcal3layers());
      histograms.h_cl3d_firstHcal5layers_->Fill(cl3d_itr->firstHcal5layers());
      histograms.h_cl3d_last1layers_->Fill(cl3d_itr->last1layers());
      histograms.h_cl3d_last3layers_->Fill(cl3d_itr->last3layers());
      histograms.h_cl3d_last5layers_->Fill(cl3d_itr->last5layers());
      histograms.h_cl3d_emax1layers_->Fill(cl3d_itr->emax1layers());
      histograms.h_cl3d_emax3layers_->Fill(cl3d_itr->emax3layers());
      histograms.h_cl3d_emax5layers_->Fill(cl3d_itr->emax5layers());
      histograms.h_cl3d_eot_->Fill(cl3d_itr->eot());
      histograms.h_cl3d_ebm0_->Fill(cl3d_itr->ebm0());
      histograms.h_cl3d_ebm1_->Fill(cl3d_itr->ebm1());
      histograms.h_cl3d_hbm_->Fill(cl3d_itr->hbm());
      histograms.h_cl3d_ntc67_->Fill(cl3d_itr->triggerCells67percent());
      histograms.h_cl3d_ntc90_->Fill(cl3d_itr->triggerCells90percent());
      histograms.h_cl3d_bdteg_->Fill(id_->value(*cl3d_itr));
      histograms.h_cl3d_quality_->Fill(cl3d_itr->hwQual());
    }
  }
  histograms.h_cl3d_n_->Fill(cl3d_n);

  // retrieve towers
  edm::Handle<l1t::HGCalTowerBxCollection> towers_h;
  iEvent.getByToken(towers_token_, towers_h);
  const l1t::HGCalTowerBxCollection &towers = *towers_h;

  if (towers_h.isValid()) {
    for (auto tower_itr = towers.begin(0); tower_itr != towers.end(0); tower_itr++) {
      tower_n++;
      histograms.h_tower_pt_->Fill(tower_itr->pt());
      histograms.h_tower_energy_->Fill(tower_itr->energy());
      histograms.h_tower_eta_->Fill(tower_itr->eta());
      histograms.h_tower_phi_->Fill(tower_itr->phi());
      histograms.h_tower_etEm_->Fill(tower_itr->etEm());
      histograms.h_tower_etHad_->Fill(tower_itr->etHad());
      histograms.h_tower_iEta_->Fill(tower_itr->id().iEta());
      histograms.h_tower_iPhi_->Fill(tower_itr->id().iPhi());
    }
  }
  histograms.h_tower_n_->Fill(tower_n);
}

#include "FWCore/Framework/interface/MakerMacros.h"

//define this as a plug-in
DEFINE_FWK_MODULE(HGCalTriggerValidator);
