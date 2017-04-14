
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
    G4Box * gamma_box = new G4Box("g_b", 100*mm, 100*mm, 100*mm);
    G4LogicalVolume* log_gamma_box = new G4LogicalVolume(gamma_box, material, "log_g_b");
    log_gamma_box->SetVisAttributes(G4Color(0.0, 0.60, 1.0));
    new G4PVPlacement(0, G4ThreeVector(0,0,-200),log_gamma_box,"pl_g_b",logicWorld,false,0);
    G4Sphere * beta_sphere = new G4Sphere("b_s",0,150,0,360*deg,0,360*deg);
    G4LogicalVolume* log_beta_sphere = new G4LogicalVolume(beta_sphere, material, "log_g_b");
    log_beta_sphere->SetVisAttributes(G4Color(1.0, 0.40, 0.30));
    new G4PVPlacement(0, G4ThreeVector(0,-300,200),log_beta_sphere,"pl_g_b",logicWorld,false,0);
    G4cout<<"Geometry of detector is build successfully\t\t\t\t\t\tOK!!!"<<G4endl;
    return physWorld;
}


