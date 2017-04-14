
#include <G4PhysicalConstants.hh>
#include <G4VisAttributes.hh>
#include <G4Sphere.hh>
#include "DetGeometry.hh"

DetGeometry::DetGeometry() {
    world_sizeXYZ   = 50 * m;
    nist            = G4NistManager::Instance();
    material       = nist->FindOrBuildMaterial("G4_AIR");
    solidWorld      = new G4Box("solWorld", 0.5*world_sizeXYZ, 0.5*world_sizeXYZ, 0.5*world_sizeXYZ);
    logicWorld      = new G4LogicalVolume(solidWorld, material, "logWorld");
    physWorld       = new G4PVPlacement(0, G4ThreeVector(), logicWorld, "phyWorld", 0, false, 0);
   }

DetGeometry::~DetGeometry() {}

G4VPhysicalVolume* DetGeometry::Construct(){
    G4Box * beta_box = new G4Box("b_b", 100*mm, 100*mm, 100*mm);
    G4LogicalVolume* log_beta_box = new G4LogicalVolume(beta_box, material, "log_b_b");
    log_beta_box->SetVisAttributes(G4Color(1.0, 0.40, 0.30));
    new G4PVPlacement(0, G4ThreeVector(-100,0,200),log_beta_box,"pl_b_b",logicWorld,false,0);
    G4Sphere * gamma_sphere = new G4Sphere("g_s",0,130,0,360*deg,0,360*deg);
    G4LogicalVolume* log_gamma_sphere = new G4LogicalVolume(gamma_sphere, material, "log_g_s");
    log_gamma_sphere->SetVisAttributes(G4Color(0.0, 1.00, 0.0));
    new G4PVPlacement(0, G4ThreeVector(0,-300,200),log_gamma_sphere,"pl_g_s",logicWorld,false,0);
    G4cout<<"Geometry of detector is build successfully\t\t\t\t\t\tOK!!!"<<G4endl;
    return physWorld;
}


