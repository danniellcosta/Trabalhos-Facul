using UnityEngine;

[RequireComponent(typeof(Rigidbody2D))]
public class Movimento : MonoBehaviour
{

    [SerializeField] private float distanciaDeVerificacao = 0.5f;
    public static Vector2 tamanhoDoBoxCast = new Vector2(0.5f, 1f);
    public static LayerMask layerMask;
    public float velocidade = 8.0f;
    public float Multiplicador = 1.0f;
    public Vector2 DirecaoInicial;
    public LayerMask layerParede;
    public Rigidbody2D rgdb2D { get; private set; }
    public Vector2 direcao { get; private set; }
    public Vector2 proxDirecao { get; private set; }
    public Vector3 posicaoInicial { get; private set; }

    private void Awake()
    {
        this.rgdb2D = GetComponent<Rigidbody2D>();
        this.posicaoInicial = this.transform.position;
    }

    private void Start()
    {
        ResetState();
    }

    public void ResetState()
    {
        this.Multiplicador = 1.0f;
        this.direcao = this.DirecaoInicial;
        this.proxDirecao = Vector2.zero;
        this.transform.position = this.posicaoInicial;
        this.rgdb2D.isKinematic = false;
        this.enabled = true;
    }

    private void Update()
    {
        if (this.proxDirecao != Vector2.zero)
        {
            SetDirecao(this.proxDirecao);
        }
    }

    private void FixedUpdate()
    {
        Vector2 posicao = this.rgdb2D.position;
        Vector2 translate = this.direcao * this.velocidade * this.Multiplicador * Time.fixedDeltaTime;
        this.rgdb2D.MovePosition(posicao + translate);
    }

    public void SetDirecao(Vector2 direcao, bool forcado = false)
    {
        if (forcado || !Ocupado(direcao))
        {
            this.direcao = direcao;
            this.proxDirecao = Vector2.zero;
        }
        else
        {
            this.proxDirecao = direcao;
        }
    }

    public bool Ocupado(Vector2 direcao)
    {
        Vector2 start = transform.position;
        Vector2 end = start + direcao * distanciaDeVerificacao;

        // Executa o BoxCast na direção desejada
        RaycastHit2D hit = Physics2D.BoxCast(start, tamanhoDoBoxCast, 0, direcao, distanciaDeVerificacao, layerMask);

        return hit.collider != null;
    }


}
