# APx Gen2 Phase2 GCT

GCT project: phi stitching part of the code
- To be used in SLR-2: combine output of eta stitched from  
  SLR-0 and  SLR-1.

## Simulation and Synthesis:

For HLS simulation
```bash
cd phiStitch/hls/vivado_hls/
vivado_hls -f run_hls.tcl csim=1 tv_in=$PWD/data/test_in.txt tv_out=$PWD/data/test_out.txt tv_ref=$PWD/data/test_out_ref.txt
```

Synthesis and exporting RTL
```bash
cd phiStitch/hls/vivado_hls/
vivado_hls -f run_hls.tcl synth=1 export=1

```
Simulation, Synthesis, Verification and RTL generation in Vivado HLS:
```bash
cd phiStitch/hls/vivado_hls/
vivado_hls -f run_hls.tcl csim=1 synth=1 cosim=1 export=1 tv_in=$PWD/data/test_in.txt tv_out=$PWD/data/test_out.txt tv_ref=$PWD/data/test_out_ref.txt
```

## Making bit file for APd:
```
cd $AP_FW_BASE_DIR/phase2-gct/
mkdir build
make
```

## GUI access
 
Follow instructions at twiki - adapt suitably for usage on beck.hep.wisc.edu:
https://twiki.cern.ch/twiki/bin/viewauth/CMS/L1TriggerPhase2HLSProjects
