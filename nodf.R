getwd()
setwd('/home/josera/Dropbox/StructuralvsAttractingNetworks/Nestedness/FALCON-master/R/')
LOADEDMAT<- read.csv('bicon45.csv', sep=",")
# h <- LOADEDMAT.nrows()
for (i in 0:557){
  j=5*i
  LOAN <- as.matrix(LOADEDMAT[c(j+1,j+2,j+3,j+4,j+5),])
  ind2 <- PERFORM_NESTED_TEST(LOAN,1,1,c('NODF'),c(1,2),1000,0)
  indfile <- ind2[["Bin_t1"]][["NODF"]][["Measure"]]
  write.table(indfile, file = "biconv54Rbnodf.txt", append = TRUE, quote = TRUE, sep = " ",
              eol = "\n", na = "NA", dec = ".", row.names = TRUE,
              col.names = TRUE, qmethod = c("escape", "double"))
}

