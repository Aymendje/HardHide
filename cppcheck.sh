SCRIPTPATH=`pwd`
CODE_ENC_PATH="$SCRIPTPATH/srcEnc"
CODE_DEC_PATH="$SCRIPTPATH/srcDec"


cppcheck --force \
		 --inline-suppr  \
		 --template '{file}:{line},{severity},{id},{message}' \
		 $CODE_ENC_PATH

cppcheck --force \
		 --inline-suppr  \
		 --template '{file}:{line},{severity},{id},{message}' \
		 $CODE_DEC_PATH