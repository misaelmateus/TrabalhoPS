-- Ativa restrição de chave extrangeira
PRAGMA foreign_keys = ON;

DROP TABLE IF EXISTS usuario;
DROP TABLE IF EXISTS credencial;

-- Usuario
CREATE TABLE usuario (
       id INTEGER PRIMARY KEY AUTOINCREMENT,
       nome VARCHAR(20) NOT NULL,
       sobrenome VARCHAR(50) NOT NULL
);

-- Credenciais
CREATE TABLE credencial (
       usuarioID INTEGER NOT NULL,
       username VARCHAR(20) NOT NULL,
       password VARCHAR(20) NOT NULL,
       CONSTRAINT pk_credencial PRIMARY KEY(username),
       FOREIGN KEY(usuarioID) REFERENCES usuario(id)
);

-- Inserir alguns valores
INSERT INTO usuario(nome,sobrenome) VALUES
       ('fabricio','sanches'),
       ('felipe','gemmal'),
       ('daniel','ventura');

INSERT INTO credencial(usuarioID,username,password) VALUES
       ((SELECT id FROM usuario WHERE nome='fabricio'), 'fabs','senha_fabricio'),
       ((SELECT id FROM usuario WHERE nome='felipe'), 'gemmalis','senha_gemmal'),
       ((SELECT id FROM usuario WHERE nome='daniel'), 'lambda','senha_lambda');
