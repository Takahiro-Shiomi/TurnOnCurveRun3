#!/bin/sh
rm TurnoncurvE.out
cp ../build/test/TurnoncurvE.out .

PDF_LABEL="TurnOnCurve_15thre_SingleMuon_Run3_NewCW_HotRoI"

INPUT_NTUPLE="/gpfs/fs7001/shiomi/ATLAS/Residual/Ntuple/L1TGCNtupleRun3/run/CW_MC_SingleMuon_NewCW_1007_Histgram.root"
#INPUT_NTUPLE="/gpfs/fs7001/shiomi/ATLAS/Residual/Ntuple/L1TGCNtupleRun3/run/CW_MC_SingleMuon_NewCWCleaner_4_Histgram.root"
#INPUT_NTUPLE="/gpfs/fs7001/shiomi/ATLAS/Residual/Ntuple/L1TGCNtupleRun3/run2/CW_MC_SingleMuon_NewCWCleaner_5_Histgram.root"

#LIMIT_ENTRY=200
LIMIT_ENTRY=-1
#TRIG_CHAIN=0

echo ""
echo "PDF_LABEL: "${PDF_LABEL}
echo "INPUT_NTUPLE: "${INPUT_NTUPLE}
echo ""

COMMAND="./TurnoncurvE.out ${PDF_LABEL} ${INPUT_NTUPLE} ${LIMIT_ENTRY}"

eval ${COMMAND} 2>&1

#eof
