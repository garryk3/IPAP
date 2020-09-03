INSERT INTO [IPAP].[dbo].[Test](FIO)
VALUES ('1111'),
       ('1112'),
       ('1113'),
       ('1114')
GO
SELECT TOP (1000) [ID]
      ,[FIO]
  FROM [IPAP].[dbo].[Test]