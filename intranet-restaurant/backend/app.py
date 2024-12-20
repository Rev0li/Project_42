from flask import Flask
from auth.routes import auth_bp

app = Flask(__name__)

# Enregistrer le blueprint du module d'authentification
app.register_blueprint(auth_bp, url_prefix="/auth")

if __name__ == "__main__":
    app.run(debug=True)

