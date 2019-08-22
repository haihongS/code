Tera api
=======
## stratum <-> node
### getwork
/api/v2/GetWork
```
{
  "result":1,
  "data":[
    "35752521", // BlockNum
    "210803", // MinerId
    "f1b9f6539c4391225ea4f0f760428c576c8b7ca6a5814fe6bb350314998472b4", // SeqHash
    "37797691fb3ee3fbe7fc515a75a8543a95396e502096e6ec1a78b0e938818106" // PrevHash
  ]
}
```
### submit
/api/v2/Submit
```
{
  "", // BlockNum
  "", // SeqHash
  "", // Hash
  "", // PowHash
  "", // Addrhash
}
```

## stratum <-> miner
### login
```
{
  id: 3,
  method: "login",
  params: ["accout.miner"],
}
```

### notify
```
{
  id: 3,
  method: "notify",
  result: [
    "11", // JobId
    "15", // RunRange
    "23", // StNonce
    "23", // BlockNum
    "33", // MinerId
    "f2", // PrevHash
    "3f", // SeqHash
  ],
}
```

### submit
```
{
  id: 175416,
  method: "submit",
  result: [
    "5095495887142307967", // JobId
    "225abf1", // BlockNum
    "295da1162d04d85524a5383fa49261f892ce542729ca7e780d4e068696792d20", // SeqHash
    "fc0822c6362c806046d97dbd79cb6df4f5515819c674a1bfcaf683cdda3003f9", // Hash
    "0000000150bc4429c44d451ce7a559a0b58cb5ae61a8c51009533c1e789e251b", // PowHash
    "7337030000006b3d080000055002702b00006f1206780000fc05c201725e8c02", // AddrHash
  ],
}

```
