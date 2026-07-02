pipeline {
    agent any

    options {
        skipStagesAfterUnstable()
    }

    stages {

        stage('Build') {
            steps {
                echo 'Compilando aplicacion principal con cobertura...'

                bat '"C:\\msys64\\ucrt64\\bin\\g++.exe" --coverage main.cpp -o app.exe'

                echo 'Ejecutando aplicacion principal para generar cobertura de main.cpp...'
                bat 'app.exe'
            }
        }

        stage('Test') {
            steps {
                echo 'Compilando tests con cobertura...'

                bat '"C:\\msys64\\ucrt64\\bin\\g++.exe" --coverage test.cpp -o test.exe'

                echo 'Ejecutando tests...'

                bat 'test.exe > resultado-tests.txt'

                bat 'type resultado-tests.txt'
            }
        }

        stage('Ver ficheros de cobertura') {
            steps {
                echo 'Mostrando ficheros .gcno y .gcda generados...'

                bat 'dir *.gcno'
                bat 'dir *.gcda'
            }
        }

        stage('Generar Cobertura') {
            steps {
                echo 'Generando informes gcov desde todos los ficheros .gcno...'

                bat '''
                for %%F in (*.gcno) do (
                    echo Procesando %%F
                    "C:\\msys64\\ucrt64\\bin\\gcov.exe" "%%F"
                )
                '''

                echo 'Mostrando informes .gcov generados...'
                bat 'dir *.gcov'
            }
        }

        stage('Analisis SonarCloud') {
            steps {
                echo 'Enviando analisis a SonarCloud...'

                withSonarQubeEnv('SonarCloud') {
                    bat '"C:\\sonar-scanner\\bin\\sonar-scanner.bat"'
                }
            }
        }

        stage('Quality Gate') {
            steps {
                echo 'Esperando resultado del Quality Gate...'

                timeout(time: 5, unit: 'MINUTES') {
                    waitForQualityGate abortPipeline: true
                }
            }
        }

        stage('Publish') {
            steps {
                echo 'Publicando artefactos...'

                archiveArtifacts artifacts: 'programa.exe,test.exe,resultado-tests.txt,*.gcno,*.gcda,*.gcov',
                                 fingerprint: true
            }
        }
    }

    post {

        success {
            echo 'Pipeline completada correctamente.'
        }

        failure {
            echo 'Pipeline fallida.'
        }

        unstable {
            echo 'Pipeline inestable.'
        }

        always {
            echo 'Fin de la ejecucion.'
        }
    }
}
