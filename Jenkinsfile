pipeline {
    agent any

    environment {
        GIT_REPO = 'https://github.com/yourusername/your-repo-name.git' // Replace with your GitHub repo URL
    }

    stages {
        stage('Checkout') {
            steps {
                git branch: 'main', url: "${GIT_REPO}"
            }
        }

        stage('Install Dependencies') {
            steps {
                script {
                    // Install gcc and make on the agent if not installed already
                    sh '''
                    sudo apt update
                    sudo apt install -y g++ make
                    sudo apt install -y libtinyxml2.6.2v5 libtinyxml2-dev
                    '''
                }
            }
        }

        stage('Build') {
            steps {
                script {
                    // Run the make command to compile the code
                    sh 'make'
                }
            }
        }

        stage('Run') {
            steps {
                script {
                    // Assuming the XML file is available in the same directory
                    sh './xml_parser catalog.xml'
                }
            }
        }

        stage('Clean') {
            steps {
                // Clean the build artifacts
                sh 'make clean'
            }
        }
    }

    post {
        always {
            // Actions to take after the pipeline runs (e.g., email notifications, etc.)
        }
    }
}
