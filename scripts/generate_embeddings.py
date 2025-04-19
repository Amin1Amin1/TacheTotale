import sys
import json
from sentence_transformers import SentenceTransformer
import numpy as np

# Charger le modèle
model = SentenceTransformer('sentence-transformers/all-MiniLM-L6-v2')

# Lire les entrées depuis les arguments
inputs = json.loads(sys.argv[1])  # Liste des textes : [magasin_desc, produit1, produit2, ...]

# Générer les embeddings
embeddings = model.encode(inputs, convert_to_numpy=True)

# Convertir en liste pour JSON
embeddings_list = embeddings.tolist()

# Afficher les embeddings sous forme de JSON
print(json.dumps(embeddings_list))