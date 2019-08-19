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
  id: 4,
  method: "submit",
  result: [
    "11", // JobId
    "af", // BlockNum
    "ac", // SeqHash
    "ac", // Hash
    "ac", // PowHash
    "ac", // AddrHash
  ],
}

```
