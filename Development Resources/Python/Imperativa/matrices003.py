damnif = [[1 for c in range(4)] for f in range(6)]

damnif[0][0] = 110698
damnif[0][1] = 125147
damnif[0][2] = 257321
damnif[0][3] = 389010

damnif[1][0] = 98742
damnif[1][1] = 123654
damnif[1][2] = 325698
damnif[1][3] = 282965

damnif[2][0] = 187524
damnif[2][1] = 204287
damnif[2][2] = 149528
damnif[2][3] = 228914

damnif[3][0] = 108111
damnif[3][1] = 198365
damnif[3][2] = 206879
damnif[3][3] = 216758

damnif[4][0] = 65541
damnif[4][1] = 54211
damnif[4][2] = 100365
damnif[4][3] = 169446

damnif[5][0] = 105230
damnif[5][1] = 98745
damnif[5][2] = 203698
damnif[5][3] = 119575

for i in range(6):
    print(damnif[i])

damnif_año = [0]*4

for i in range(4):
    for j in range(6):
        damnif_año[i] += damnif[j][i]

print(damnif_año)